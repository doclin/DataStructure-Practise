#ifndef _BINARY_TREE_ITERATOR_INCLUDED_
#define _BINARY_TREE_ITERATOR_INCLUDED_
#include "binary_tree.h"
#include "../stack/stack.h"

template <typename Type>
class BaseIterator
{
protected:
	Stack<BinTreeNode<Type>*> stack;
	BinaryTree<Type>& tree;
	BinTreeNode<Type>* current;
public:
	virtual BinTreeNode<Type>* first()=0;
	virtual BinTreeNode<Type>* next()=0;
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p))=0;
};


template <typename Type>
class PreOrderIterator : public BaseIterator<Type>
{
public:
	PreOrderIterator(BinaryTree<Type>& bt): tree(bt), current(NULL) {}
	virtual BinTreeNode<Type>* first();
	virtual BinTreeNode<Type>* next();
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p));
};


template <typename Type>
class InOrderIterator : public BaseIterator<Type>
{
public:
	InOrderIterator(BinaryTree<Type>& bt): tree(bt), current(NULL) {}
	virtual BinTreeNode<Type>* first();
	virtual BinTreeNode<Type>* next();
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p));
};


template <typename Type>
class PostOrderIterator : public BaseIterator<Type>
{
public:
	PostOrderIterator(BinaryTree<Type>& bt): tree(bt), current(NULL) {}
	virtual BinTreeNode<Type>* first();
	virtual BinTreeNode<Type>* next();
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p));
};


template <typename Type>
void PreOrderIterator::traverse(void (* func)(BinTreeNode<Type>* node_p))
{
	Stack<BinTreeNode<Type>*> s; //
	BinTreeNode<Type>* curr_p = tree.get_root();
	while(curr_p!=NULL or !s.is_empty())
	{
		if(curr_p != NULL)
		{
			func(curr_p);
			s.push(curr_p);	
			curr_p = curr_p -> left_child;
		}
		else
		{
			curr_p = s.pop();
			curr_p = curr_p -> right_child;
		}
	}
}

template <typename Type>
void InOrderIterator::traverse(void (* func)(BinTreeNode<Type>* node_p))
{
	Stack<BinTreeNode<Type>*> s;
	BinTreeNode<Type>* curr_p = tree.get_root();
	while(curr_p!=NULL or !s.is_empty())
	{
		if(curr_p != NULL)
		{
			s.push(curr_p);
			curr_p = curr_p -> left_child;
		}
		else
		{
			curr_p = s.pop();
			func(curr_p);
			curr_p = curr_p -> right_child;
		}
	}
}


#endif