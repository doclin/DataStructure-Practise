#ifndef _TB_TREE_ITERATOR_H_INCLUDED_
#define _TB_TREE_ITERATOR_H_INCLUDED_

#include "threaded_binary_tree.h"
#include <iostream>
using namespace std;


template <typename Type>
class TBInOrderIterator
{
private:
	ThreadedBinTree<Type>& tree;
	TBTreeNode<Type>* current;
public:
	TBInOrderIterator(ThreadedBinTree<Type>& tbtree): tree(tbtree), current(NULL) {}
	virtual TBTreeNode<Type>* first();
	virtual TBTreeNode<Type>* last();
	virtual TBTreeNode<Type>* next();
	virtual TBTreeNode<Type>* prior();
	virtual void traverse();
};

template <typename Type>
TBTreeNode<Type>* TBInOrderIterator<Type>::first()
{
	current = tree.get_root();
	while(current->left_thread != true)
		current = current -> left_child;
	return current;
}

template <typename Type>
TBTreeNode<Type>* TBInOrderIterator<Type>::last()
{
	TBTreeNode<Type>* tmp = tree.get_root();
	while(tmp->right_thread == false)
		tmp = tmp -> right_child;
	return tmp;
}

template <typename Type>
TBTreeNode<Type>* TBInOrderIterator<Type>::next()
{
	if(current == NULL)
		return first();
	if(current->right_thread == true)
	{
		current = current -> right_child;
		return current;
	}
	else
	{
		current = current -> right_child;
		while(current->left_thread != true)
			current = current -> left_child;
		return current;
	}
}

template <typename Type>
TBTreeNode<Type>* TBInOrderIterator<Type>::prior()
{
	if(current == NULL)
		return NULL;
	if(current->left_thread == true)
	{
		current = current -> left_child;
		return current;
	}
	else
	{
		current = current -> left_child;
		while(current->right_thread != true)
			current = current -> right_child;
		return current;
	}
}

template <typename Type>
void TBInOrderIterator<Type>::traverse()
{
	while(next() != NULL)
		cout << current -> element;
	cout << endl;
}


#endif