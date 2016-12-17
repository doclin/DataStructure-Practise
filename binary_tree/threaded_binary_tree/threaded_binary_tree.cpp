#include <iostream>
#include "threaded_binary_tree.h"
#include "tb_tree_iterator.h"
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
	BinaryTree<char> btree = get_char_tree();
	//btree.pre_order();                         // ABDCEF
	ThreadedBinTree<char> tbtree(btree);
	TBInOrderIterator<char> iterator(tbtree);
	iterator.traverse();                         // BDAECF
	cout << iterator.first() -> element << endl; // B
	cout << iterator.next() -> element << endl;  // D
	cout << iterator.next() -> element << endl;  // A
	cout << iterator.prior() -> element << endl; // D
	cout << iterator.prior() -> element << endl; // B
	cout << iterator.last() -> element << endl;  // F

	return 0;
}