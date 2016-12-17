#ifndef _THREADED_BINARY_TREE_INCLUDED_
#define _THREADED_BINARY_TREE_INCLUDED_
#include <iostream>
#include "../binary_tree.h"
using namespace std;

enum threaded_order {pre_order, in_order, post_order};

template <typename Type>
class TBTreeNode
{
public:
	Type element;
	TBTreeNode<Type>* left_child;
	TBTreeNode<Type>* right_child;	
	bool left_thread;
	bool right_thread;
	TBTreeNode(
		Type e=0, TBTreeNode<Type>* pl=NULL, TBTreeNode<Type>* pr=NULL, bool lt=false, bool rt=false
		): element(e), left_child(pl), right_child(pr), left_thread(lt), right_thread(rt) {}
	TBTreeNode(const BinTreeNode<Type>& n)
		: element(n.element), left_child(NULL), right_child(NULL), left_thread(false), right_thread(false) {}
};


template <typename Type>
class ThreadedBinTree
{
private:
	TBTreeNode<Type>* root;
	threaded_order order_type;
	TBTreeNode<Type>* copy(TBTreeNode<Type>*);
	TBTreeNode<Type>* copy(BinTreeNode<Type>*);
	void clear(TBTreeNode<Type>*);
	void clear_threads(TBTreeNode<Type>*);		
	void create_inorder_thread(TBTreeNode<Type>*, TBTreeNode<Type>*&);	
public:
	ThreadedBinTree(): root(NULL), order_type(in_order) {}
	ThreadedBinTree(const Type&);
	ThreadedBinTree(const ThreadedBinTree&);
	ThreadedBinTree(const BinaryTree<Type>&);
	ThreadedBinTree<Type>& operator=(const ThreadedBinTree&);
	ThreadedBinTree<Type>& operator=(const BinaryTree<Type>&);
	void clear();
	~ThreadedBinTree();
	bool is_empty() const;
	TBTreeNode<Type>* get_root() const { return root; }
	void create_inorder_thread();
};


template <typename Type>
ThreadedBinTree<Type>::ThreadedBinTree(const Type& x)
	: order_type(in_order)
{
	root = new TBTreeNode<Type>(x);
}

template <typename Type>
ThreadedBinTree<Type>::ThreadedBinTree(const ThreadedBinTree& tbtree)
{
	root = copy(tbtree.root);
	order_type = tbtree.order_type;
	create_inorder_thread();
}

template <typename Type>
ThreadedBinTree<Type>::ThreadedBinTree(const BinaryTree<Type>& btree)
{
	root = copy(btree.get_root());
	order_type = in_order;
	create_inorder_thread();
}

template <typename Type>
ThreadedBinTree<Type>& ThreadedBinTree<Type>::operator=(const ThreadedBinTree& tbtree)
{
	clear(root);
	root = copy(tbtree.root);
	order_type = tbtree.order_type;
	create_inorder_thread();
	return *this;
}

template <typename Type>
ThreadedBinTree<Type>& ThreadedBinTree<Type>::operator=(const BinaryTree<Type>& btree)
{
	clear(root);
	root = copy(btree.get_root());
	order_type = in_order;
	create_inorder_thread();
	return *this;
}

template <typename Type>
TBTreeNode<Type>* ThreadedBinTree<Type>::copy(TBTreeNode<Type>* p)
{
	if(p == NULL)
		return NULL;
	TBTreeNode<Type>* new_p = new TBTreeNode<Type>(*p);
	if(p->left_thread == false)
		new_p -> left_child = copy(p -> left_child);
	if(p->right_thread == false)
		new_p -> right_child = copy(p -> right_child);

	return new_p;
}

template <typename Type>
TBTreeNode<Type>* ThreadedBinTree<Type>::copy(BinTreeNode<Type>* p)
{
	if(p == NULL)
		return NULL;
	TBTreeNode<Type>* new_p = new TBTreeNode<Type>(*p);	
	if(p->left_child != NULL)
		new_p -> left_child = copy(p -> left_child);
	if(p->right_child != NULL)
		new_p -> right_child = copy(p -> right_child);

	return new_p;
}

template <typename Type>
void ThreadedBinTree<Type>::clear()
{
	clear(root);
	root = NULL;
}

template <typename Type>
void ThreadedBinTree<Type>::clear(TBTreeNode<Type>* p)
{
	if(p != NULL)
	{
		if(p->left_thread == false)
			clear(p -> left_child);
		if(p->right_thread == false)
			clear(p -> right_child);
		delete p;		
	}
}

template <typename Type>
void ThreadedBinTree<Type>::clear_threads(TBTreeNode<Type>* p)
{
	if(p != NULL)
	{
		if(p->left_thread == false)
			clear_threads(p -> left_child);
		else
		{
			p -> left_child = NULL;
			p -> left_thread = false;
		}

		if(p->right_thread == false)
			clear_threads(p -> right_child);
		else
		{
			p -> right_child = NULL;
			p -> right_thread = false;
		}
	}
}

template <typename Type>
ThreadedBinTree<Type>::~ThreadedBinTree()
{
	clear();
}

template <typename Type>
bool ThreadedBinTree<Type>::is_empty() const
{
	if(root == NULL)
		return true;
	return false;
}

template <typename Type>
void ThreadedBinTree<Type>::create_inorder_thread()
{
	clear_threads(root);
	TBTreeNode<Type>* tmp = NULL;
	create_inorder_thread(root, tmp);
}

template <typename Type>
void ThreadedBinTree<Type>::create_inorder_thread(TBTreeNode<Type>* p, TBTreeNode<Type>*& pre)
{
	if(p != NULL)
	{
		if(p->left_child == NULL)
		{
			p -> left_child = pre;
			p -> left_thread = true;
		}
		else
			create_inorder_thread(p -> left_child, pre);

		if(pre!=NULL and pre->right_child==NULL)
			pre -> right_child = p;

		pre = p;
		if(p->right_child == NULL)
			p -> right_thread = true;
		else
			create_inorder_thread(p -> right_child, pre);
	}

}

#endif