#ifndef _COMPLETE_BINARY_TREE_H_INCLUDED_
#define _COMPLETE_BINARY_TREE_H_INCLUDED_

#include "binary_tree.h"
#include "../queue/queue.h"

template <typename Type>
class CompleteBinTree : public BinaryTree<Type>
{
public:
	CompleteBinTree() : BinaryTree<Type>::BinaryTree() {}
	CompleteBinTree(const Type& x) : BinaryTree<Type>::BinaryTree(x) {}
	CompleteBinTree(Type* p, int len);
	CompleteBinTree(const CompleteBinTree& t) : BinaryTree<Type>::BinaryTree(t) {}
	CompleteBinTree<Type>& operator=(const CompleteBinTree& t);
	virtual ~CompleteBinTree() {}
	virtual void make_complete_tree(Type* p, int len);
};

template <typename Type>
CompleteBinTree<Type>::CompleteBinTree(Type* p, int len)
{
	if(len > 0)
	{
		Queue<BinTreeNode<Type>*> queue;
		BinaryTree<Type>::root = new BinTreeNode<Type>(p[0]);
		queue.enqueue(BinaryTree<Type>::root);
		for(int i=1; i<len; i++)
		{
			if(queue.get_front_element()->left_child == NULL)
			{
				queue.get_front_element() -> left_child = new BinTreeNode<Type>(p[i]);
				queue.enqueue(queue.get_front_element() -> left_child);
			}
			else
			{
				queue.get_front_element() -> right_child = new BinTreeNode<Type>(p[i]);
				queue.enqueue(queue.get_front_element() -> right_child);
				queue.dequeue();
			}
		}
	}
}

template <typename Type>
CompleteBinTree<Type>& CompleteBinTree<Type>::operator=(const CompleteBinTree& t)
{
	BinaryTree<Type>::operator=(t);
	return *this;
}

template <typename Type>
void CompleteBinTree<Type>::make_complete_tree(Type* p, int len)
{
	BinaryTree<Type>::clear();
	if(len > 0)
	{
		Queue<BinTreeNode<Type>*> queue;
		BinaryTree<Type>::root = new BinTreeNode<Type>(p[0]);
		queue.enqueue(BinaryTree<Type>::root);
		for(int i=1; i<len; i++)
		{
			if(queue.get_front_element()->left_child == NULL)
			{
				queue.get_front_element() -> left_child = new BinTreeNode<Type>(p[i]);
				queue.enqueue(queue.get_front_element() -> left_child);
			}
			else
			{
				queue.get_front_element() -> right_child = new BinTreeNode<Type>(p[i]);
				queue.enqueue(queue.get_front_element() -> right_child);
				queue.dequeue();
			}
		}
	}	
}






#endif