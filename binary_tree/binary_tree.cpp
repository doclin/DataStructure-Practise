#include "binary_tree.h"
#include <iostream>

BinaryTree<char>& get_char_tree();

int main()
{
	BinaryTree<char> tree = get_char_tree();
	tree.pre_order(tree.get_root());
	std::cout << "-----------" << std::endl;
	tree.in_order(tree.get_root());
	std::cout << "-----------" << std::endl;
	tree.post_order(tree.get_root());

	
	return 0;
}

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