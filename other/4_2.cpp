#include "../binary_tree/binary_tree.h"
#include "../queue/queue.h"
#include <iostream>

using namespace std;

template <typename Type>
struct SeqNode
{
	Type element;
	Type parent;
	bool flag;//
};

SeqNode<char>* get_char_sequence()
{
	SeqNode<char>* arr = new SeqNode<char>[8]; //
	arr[0].element = 'A';
	arr[0].parent = 0;
	arr[0].flag = false;
	arr[1].element = 'B';
	arr[1].parent = 'A';
	arr[1].flag = false;
	arr[2].element = 'C';
	arr[2].parent = 'A';
	arr[2].flag = false;
	arr[3].element = 'D';
	arr[3].parent = 'B';
	arr[3].flag = true;
	arr[4].element = 'E';
	arr[4].parent = 'C';
	arr[4].flag = false;
	arr[5].element = 'F';
	arr[5].parent = 'C';
	arr[5].flag = false;
	arr[6].element = 'G';
	arr[6].parent = 'E';
	arr[6].flag = false;
	arr[7].element = 'H';
	arr[7].parent = 'E';
	arr[7].flag = false;		

	return arr;					
}

template <typename Type>
BinaryTree<Type> get_tree(SeqNode<Type>* array, int length)
{
	if(length == 0)
	{
		BinaryTree<Type> empty_tree;
		return empty_tree;
	}
	Queue<BinTreeNode<Type>*> queue;
	BinaryTree<Type> tree = BinaryTree<Type>(array[0].element);
	queue.enqueue(tree.get_root());
	for(int i=1; i<length; i++)
	{
		while(queue.get_front_element()->element != array[i].parent)
			queue.dequeue();
		if(queue.get_front_element()->left_child!=NULL or array[i].flag==true)
		{
			queue.get_front_element() -> right_child = new BinTreeNode<Type>(array[i].element);
			queue.enqueue(queue.get_front_element() -> right_child);
		}
		else
		{
			queue.get_front_element() -> left_child = new BinTreeNode<Type>(array[i].element);
			queue.enqueue(queue.get_front_element() -> left_child);
		}
	}

	return tree;
}

int main()
{
	SeqNode<char>* array = get_char_sequence();
	BinaryTree<char> tree = get_tree(array, 8);
	tree.pre_order();                  // ABDCEGHF
	cout << endl;
	tree.in_order();                   // BDAGEHCF
	cout << endl;
	tree.post_order();                 // DBGHEFCA
	delete array;

	return 0;
}