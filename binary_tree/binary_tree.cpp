#include "binary_tree.h"
#include <iostream>

using namespace std;
BinaryTree<char> get_char_tree();

int main()
{
	BinaryTree<char> tree = get_char_tree();
	cout << tree.count() << endl;                    // 6
	cout << tree.get_root() -> element << endl;      // A
	tree.pre_order();                                // ABDCEF
	cout << endl;
	tree.in_order();                                 // BDAECF
	cout << endl;
	tree.post_order();                               // DBEFCA
	cout << endl;
	BinaryTree<char> clonetree(tree);
	clonetree.pre_order();                           // ABDCEF
	cout << endl;
	clonetree.clear();
	cout << clonetree.is_empty() << endl;            // 1
	clonetree = tree;
	cout << clonetree.count() << endl;               // 6
	
	return 0;
}

BinaryTree<char> get_char_tree()
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