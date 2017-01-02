#include <iostream>
#include "binary_search_tree.h"
#include "../binary_tree.h"

using namespace std;

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
	BSTree<char> tree1;
	tree1.insert('D');
	tree1.insert('E');
	tree1.insert('F');
	tree1.insert('A');
	tree1.insert('B');
	tree1.insert('C');	
	//tree1.in_order();
	
	BSTree<char> tree2(get_char_tree());
	cout << tree1.search('C') << endl;    // 1
	tree1.remove('A');
	cout << tree1.search('F') << endl;    // 1
	cout << tree1.search('z') << endl;    // 0
	tree1.in_order();
	cout << "---------" << endl;	
	tree2.insert('Z');
	cout << tree2.search('Z') << endl;    // 1
	tree1.clear();
	tree1 = tree2;
	tree2.in_order();
	cout << "---------" << endl;
	tree1.in_order();
	/*
	*/

}