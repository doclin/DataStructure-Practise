#ifndef _BINARY_TREE_H_INCLUDED_
#define _BINARY_TREE_H_INCLUDED_

#include <iostream>


template <typename Type>
class BinTreeNode
{
public:
	Type element;
	BinTreeNode<Type>* left_child;
	BinTreeNode<Type>* right_child;	
	BinTreeNode(Type e=0, BinTreeNode<Type>* pl=NULL, BinTreeNode<Type>* pr=NULL)
	    : element(e), left_child(pl), right_child(pr) {}
};


template <typename Type>
class BinaryTree
{
protected:
	BinTreeNode<Type>* root;
public:
	BinaryTree(): root(NULL) {}
	BinaryTree(const Type& x);
	BinaryTree(const BinaryTree&);
	BinaryTree<Type>& operator=(const BinaryTree&);
	BinTreeNode<Type>* copy(BinTreeNode<Type>* p);
	void clear(BinTreeNode<Type>* p);
	void clear();		//
	virtual ~BinaryTree();
	virtual bool is_empty() const;
	virtual int count(BinTreeNode<Type>* p) const;
	virtual int count() const;//
	virtual BinTreeNode<Type>* get_root() const { return root; }
	virtual void pre_order(BinTreeNode<Type>* p) const;
	virtual void in_order(BinTreeNode<Type>* p) const;
	virtual void post_order(BinTreeNode<Type>* p) const;
	virtual void pre_order() const;//
	virtual void in_order() const;
	virtual void post_order() const;	
};


template <typename Type>
BinaryTree<Type>::BinaryTree(const Type& x)
{
	root = new BinTreeNode<Type>(x);
}

template <typename Type>
BinaryTree<Type>::BinaryTree(const BinaryTree& bt)
{
	root = copy(bt.root);
}

template <typename Type>
BinaryTree<Type>& BinaryTree<Type>::operator=(const BinaryTree& bt)
{
	clear(root);
	root = copy(bt.root);

	return *this;
}

template <typename Type>
bool BinaryTree<Type>::is_empty() const
{
	if(root == NULL)
		return true;
	return false;
}

template <typename Type>
void BinaryTree<Type>::clear(BinTreeNode<Type>* p)
{
	if(p != NULL)
	{
		clear(p -> left_child);
		clear(p -> right_child);
		delete p;		
	}
	if(p == root)
		root = NULL;
}

template <typename Type>
void BinaryTree<Type>::clear()
{
	clear(root);
}

template <typename Type>
BinTreeNode<Type>* BinaryTree<Type>::copy(BinTreeNode<Type>* p)
{
	if(p == NULL)
		return NULL;
	BinTreeNode<Type>* new_p = new BinTreeNode<Type>(*p);
	new_p -> left_child = copy(p -> left_child);
	new_p -> right_child = copy(p -> right_child);
	return new_p;
}

template <typename Type>
BinaryTree<Type>::~BinaryTree()
{
	clear(root);
}

template <typename Type>
int BinaryTree<Type>::count(BinTreeNode<Type>* p) const
{
	if(p == NULL)
		return 0;
	return 1 + count(p -> left_child) + count(p -> right_child);
}

template <typename Type>
int BinaryTree<Type>::count() const
{
	return count(root);
}

template <typename Type>
void BinaryTree<Type>::pre_order(BinTreeNode<Type>* p) const
{
	if(p!= NULL)
	{
		std::cout << p -> element << std::endl;
		pre_order(p -> left_child);
		pre_order(p -> right_child);		
	}
}

template <typename Type>
void BinaryTree<Type>::in_order(BinTreeNode<Type>* p) const
{
	if(p != NULL)
	{
		in_order(p -> left_child);
		std::cout << p -> element << std::endl;
		in_order(p -> right_child);
	}
}

template <typename Type>
void BinaryTree<Type>::post_order(BinTreeNode<Type>* p) const
{
	if(p != NULL)
	{
		post_order(p -> left_child);
		post_order(p -> right_child);		
		std::cout << p -> element << std::endl;
	}
}

template <typename Type>
void BinaryTree<Type>::pre_order() const
{
	pre_order(root);
}

template <typename Type>
void BinaryTree<Type>::in_order() const
{
	in_order(root);
}

template <typename Type>
void BinaryTree<Type>::post_order() const
{
	post_order(root);
}




#endif