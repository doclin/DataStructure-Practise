#ifndef _COMPLETE_BINARY_TREE_H_INCLUDED_
#define _COMPLETE_BINARY_TREE_H_INCLUDED_

#include "binary_tree.h"
#include "../queue/queue.h"

template <typename Type>
class CompleteBinTree : public BinaryTree
{
public:
	CompleteBinTree() : BinaryTree::BinaryTree() {}
	CompleteBinTree(const Type& x) : BinaryTree::BinaryTree(x) {}
	CompleteBinTree(Type* p, int len);
	CompleteBinTree(const CompleteBinTree& t) : BinaryTree::BinaryTree(t) {}
	CompleteBinTree<Type>& operator=(const CompleteBinTree&);
	virtual ~CompleteBinTree() {}
	virtual void make_complete_tree(Type* p, int len);
}

template <typename Type>
CompleteBinTree::CompleteBinTree(Type* p, int len)
{
	if(len > 0)
	{
		BinaryTree::BinaryTree(p[0]);
		
	}

}






#endif