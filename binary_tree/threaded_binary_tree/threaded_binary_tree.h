#ifndef _THREADED_BINARY_TREE_INCLUDED_
#define _THREADED_BINARY_TREE_INCLUDED_

#include "../binary_tree.h"

enum threaded_order {pre_order, in_order, post_order};

template <typename Type>
class TBTreeNode
{
public:
	Type element;
	bool left_thread;
	bool right_thread;
	TBTreeNode<Type>* left_child;
	TBTreeNode<Type>* right_child;
	TBTreeNode(
		Type e=0, bool lt=false, bool rt=false, TBTreeNode<Type>* pl=NULL, TBTreeNode<Type>* pr=NULL
		): element(e), left_child(pl), right_child(pr), left_thread(lt), right_thread(rt) {}
};

template <typename Type>
class ThreadedBinTree
{
private:
	threaded_order order_type = in_order;
	TBTreeNode<Type>* root;
public:
	ThreadedBinTree(): root(NULL) {}
	ThreadedBinTree(const Type&);
	ThreadedBinTree(const ThreadedBinTree&);
	ThreadedBinTree(const BinaryTree&);
	ThreadedBinTree<Type>& operator=(const ThreadedBinTree&);
	ThreadedBinTree<Type>& operator=(const BinaryTree&);
	TBTreeNode<Type>* copy(TBTreeNode<Type>*);
	TBTreeNode<Type>* copy(BinTreeNode<Type>*);
	void clear();
	void clear(TBTreeNode<Type>*);
	~ThreadedBinTree();
	bool is_empty() const;
	TBTreeNode<Type>* get_root() const { return root; }
	void create_preorder_thread();
	void create_inorder_thread();
	void create_postorder_thread();
};


template <typename Type>
ThreadedBinTree<Type>::ThreadedBinTree(const Type& x)
{
	root = new TBTreeNode<Type>(x);
}

template <typename Type>
ThreadedBinTree<Type>::ThreadedBinTree(const ThreadedBinTree& tbtree)
{
	root = copy(tbtree.root);

}

template <typename Type>
ThreadedBinTree<Type>::ThreadedBinTree(const BinaryTree& btree)
{
	root = copy(btree.root);
	create_inorder_thread();
}

template <typename Type>
ThreadedBinTree<Type>& ThreadedBinTree<Type>::operator=(const ThreadedBinTree& tbtree)
{
	clear(root);
	root = copy(tbtree.root);

	return *this;
}

template <typename Type>
ThreadedBinTree<Type>& ThreadedBinTree<Type>::operator=(const BinaryTree& btree)
{
	clear(root);
	root = copy(btree.root);

	return *this;
}

template <typename Type>
TBTreeNode<Type>* ThreadedBinTree<Type>::copy(TBTreeNode<Type>* p)
{
	BinTreeNode<Type>* new_p = new BinTreeNode<Type>(*p);
	if(p->left_thread == false)
		new_p -> left_child = copy(p -> left_child);
	if(p->right_thread == false)
		new_p -> right_child = copy(p -> right_child);

	return new_p;
}

template <typename Type>
TBTreeNode<Type>* ThreadedBinTree<Type>::copy(BinTreeNode<Type>* p)
{
	
}



	TBTreeNode<Type>* copy(TBTreeNode<Type>*);
	TBTreeNode<Type>* copy(BinTreeNode<Type>*);
	void clear();
	void clear(TBTreeNode<Type>*);
	~ThreadedBinTree();
	bool is_empty() const;
	TBTreeNode<Type>* get_root() const { return root; }
	void create_preorder_thread();
	void create_inorder_thread();
	void create_postorder_thread();







#endif