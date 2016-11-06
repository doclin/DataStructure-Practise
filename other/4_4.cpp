#include "../binary_tree/binary_tree.h"
#include "../queue/queue.h"
#include "../stack/stack.h"
#include <iostream>

using namespace std;

BinaryTree<char> get_char_tree()                                 // 获取测试用树
{
	BinaryTree<char> tree = BinaryTree<char>('A');
	BinTreeNode<char>* p = tree.get_root();
	p -> left_child = new BinTreeNode<char>('B');
	p -> right_child = new BinTreeNode<char>('C');
	p -> left_child -> right_child = new BinTreeNode<char>('D');
	p -> right_child -> left_child = new BinTreeNode<char>('E');
	p -> right_child -> right_child = new BinTreeNode<char>('F');

	return tree;
}

template <typename Type>
void traverse_in_level(BinaryTree<Type> tree, int level)
{
	Queue<BinTreeNode<Type>*> queue;
	BinTreeNode<Type>* current = tree.get_root();
	if(current == NULL)                                          // When tree is empty
		return;
	queue.enqueue(current);
	queue.enqueue(NULL);                                         // Notify each level by put NULL in queue
	for(int i=1; i<level; i++)
	{
		while(queue.get_front_element()!=NULL)                   // Judge when the level ends
		{
			current = queue.dequeue();
			if(current -> left_child != NULL)
				queue.enqueue(current->left_child);
			if(current -> right_child != NULL)
				queue.enqueue(current->right_child);
		}
		queue.dequeue();                                         // Dequeue the last NULL in queue
		queue.enqueue(NULL);                                     // Notify a new level
	}
	Stack<BinTreeNode<Type>*> stack;
	while(queue.get_front_element() != NULL)                     // turn around
	{
		current = queue.dequeue();
		stack.push(current);
	}
	while(!stack.is_empty())
		cout << stack.pop() -> element << endl;
}

int main()
{
	BinaryTree<char> tree = get_char_tree();
	traverse_in_level(tree, 1);    // A
	cout << endl;
	traverse_in_level(tree, 2);    // CB
	cout << endl;
	traverse_in_level(tree, 3);    // FED

	return 0;
}