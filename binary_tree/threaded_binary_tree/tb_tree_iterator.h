#ifndef _TB_TREE_ITERATOR_H_INCLUDED_
#define _TB_TREE_ITERATOR_H_INCLUDED_

#include "threaded_binary_tree.h"

template <typename Type>
class TBTreeIterator
{
protected:
	ThreadedBinTree<Type>& tree;
	TBTreeNode<Type>* current;
public:
	TBTreeIterator(ThreadedBinTree<Type>& tbtree): tree(tbtree), current(NULL) {}
	virtual TBTreeNode<Type>* first()=0;
	virtual TBTreeNode<Type>* last()=0;
	virtual TBTreeNode<Type>* next()=0;
	virtual TBTreeNode<Type>* prior()=0;		
	virtual void traverse()=0;
};


template <typename Type>
class TBPreOrderIterator : public TBTreeIterator<Type>
{
public:
	TBPreOrderIterator(ThreadedBinTree<Type>& tbtree)
		: TBTreeIterator<Type>::TBTreeIterator(tbtree) {}
	virtual TBTreeNode<Type>* first();
	virtual TBTreeNode<Type>* last();
	virtual TBTreeNode<Type>* next();
	virtual TBTreeNode<Type>* prior();
	virtual void traverse();
};


template <typename Type>
class TBInOrderIterator : public TBTreeIterator<Type>
{
public:
	TBInOrderIterator(ThreadedBinTree<Type>& tbtree)
		: TBTreeIterator<Type>::TBTreeIterator(tbtree) {}
	virtual TBTreeNode<Type>* first();
	virtual TBTreeNode<Type>* last();
	virtual TBTreeNode<Type>* next();
	virtual TBTreeNode<Type>* prior();
	virtual void traverse();
};


template <typename Type>
class TBPostOrderIterator : public TBTreeIterator<Type>
{
public:
	TBPostOrderIterator(ThreadedBinTree<Type>& tbtree)
		: TBTreeIterator<Type>::TBTreeIterator(tbtree) {}
	virtual TBTreeNode<Type>* first();
	virtual TBTreeNode<Type>* last();
	virtual TBTreeNode<Type>* next();
	virtual TBTreeNode<Type>* prior();
	virtual void traverse();
};


template <typename Type>
TBTreeNode<Type>* TBPreOrderIterator<Type>::first()
{
	current = tree.get_root();
	return current;
}

template <typename Type>
TBTreeNode<Type>* TBPreOrderIterator<Type>::next()
{

}













#endif