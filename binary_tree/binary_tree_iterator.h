#ifndef _BINARY_TREE_ITERATOR_INCLUDED_
#define _BINARY_TREE_ITERATOR_INCLUDED_
#include "binary_tree.h"
#include "../stack/stack.h"

template <typename Type>
class BaseIterator
{
protected:
	BinaryTree<Type>& tree;
	BinTreeNode<Type>* current;
public:
	BaseIterator(BinaryTree<Type>& bt): tree(bt), current(NULL) {}
	virtual BinTreeNode<Type>* first()=0;
	virtual BinTreeNode<Type>* next()=0;
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p))=0;
};


template <typename Type>
class PreOrderIterator : public BaseIterator<Type>
{
	Stack<BinTreeNode<Type>*> stack;
public:
	PreOrderIterator(BinaryTree<Type>& bt): BaseIterator(bt) {}
	virtual BinTreeNode<Type>* first();
	virtual BinTreeNode<Type>* next();
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p));
};


template <typename Type>
class InOrderIterator : public BaseIterator<Type>
{
	Stack<BinTreeNode<Type>*> stack;
public:
	InOrderIterator(BinaryTree<Type>& bt): BaseIterator(bt) {}
	virtual BinTreeNode<Type>* first();
	virtual BinTreeNode<Type>* next();
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p));
};


template <typename Type>
class PostOrderIterator : public BaseIterator<Type>
{
	Stack<BinTreeNode<Type>*> stack;
public:
	PostOrderIterator(BinaryTree<Type>& bt): BaseIterator(bt) {}
	virtual BinTreeNode<Type>* first();
	virtual BinTreeNode<Type>* next();
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p));
};


template <typename Type>
void PreOrderIterator<Type>::traverse(void (* func)(BinTreeNode<Type>* node_p))
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
void InOrderIterator<Type>::traverse(void (* func)(BinTreeNode<Type>* node_p))
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

template <typename Type>
void PostOrderIterator<Type>::traverse(void (* func)(BinTreeNode<Type>* node_p))
{
	Stack<BinTreeNode<Type>*> s;
	BinTreeNode<Type>* curr_p = tree.get_root();
	BinTreeNode<Type>* previsited = NULL;
	while(curr_p!=NULL or !s.is_empty())
	{
		while(curr_p != NULL)
		{
			s.push(curr_p);
			curr_p = curr_p -> left_child;
		}
		curr_p = s.get_top_element();
		if(curr_p->right_child == NULL or curr_p->right_child == previsited)
		{
			func(curr_p);
			previsited = curr_p;
			s.pop();
			curr_p = NULL;
		}
		else
			curr_p = curr_p -> right_child;
	}

}





#endif