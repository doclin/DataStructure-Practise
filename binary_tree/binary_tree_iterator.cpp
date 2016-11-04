#include <iostream>
#include "binary_tree.h"
#include "binary_tree_iterator.h"

using namespace std;

BinaryTree<char>& get_char_tree()
{
	BinaryTree<char>* tree = new BinaryTree<char>('A');
	BinTreeNode<char>* p = tree -> get_root();
	p -> left_child = new BinTreeNode<char>('B');
	p -> right_child = new BinTreeNode<char>('C');
	p -> left_child -> right_child = new BinTreeNode<char>('D');
	p -> right_child -> left_child = new BinTreeNode<char>('E');
	p -> right_child -> right_child = new BinTreeNode<char>('F');

	return *tree;
}

void func(BinTreeNode<char>* node_p)
{
	cout << node_p -> element << endl;
}

int main()
{
	BinaryTree<char> tree = get_char_tree();
	PreOrderIterator<char> pre_iterator(tree);
	InOrderIterator<char> in_iterator(tree);
	PostOrderIterator<char> post_iterator(tree);
	LevelOrderIterator<char> level_iterator(tree);
	pre_iterator.traverse(func);                         // ABDCEF
	cout << endl;
	in_iterator.traverse(func);                          // BDAECF
	cout << endl;
	post_iterator.traverse(func);                        // DBEFCA
	cout << endl;
	level_iterator.traverse(func);                       // ABCDEF
	cout << endl;
	for(int i=0; i<tree.count(); i++)
	{
		cout << pre_iterator.next() -> element << endl;  // ABDCEF
	}
	cout << endl;
	for(int i=0; i<tree.count(); i++)
	{
		cout << in_iterator.next() -> element << endl;   // BDAECF
	}	
	cout << endl;
	for(int i=0; i<tree.count(); i++)
	{
		cout << post_iterator.next() -> element << endl; // DBEFCA
	}
	cout << endl;
	for(int i=0; i<tree.count(); i++)
	{
		cout << level_iterator.next() -> element << endl; // ABCDEF
	}
	cout << endl;	
	cout << pre_iterator.first() -> element << endl;     // A
	cout << in_iterator.first() -> element << endl;      // B
	cout << post_iterator.first() -> element << endl;    // D
	cout << level_iterator.first() -> element << endl;   // A

}