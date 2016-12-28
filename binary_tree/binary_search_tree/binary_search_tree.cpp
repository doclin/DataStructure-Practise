#include <iostream>
#include "binary_search_tree.h"
#include "../binary_tree.h"

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
/*
        A
     B     C
       D  E F
*/

int main()
{


}