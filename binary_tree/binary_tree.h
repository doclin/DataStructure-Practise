#ifndef _BINARY_TREE_H_INCLUDED_
#define _BINARY_TREE_H_INCLUDED_

#include <iostream>

template <typename Type> class BinaryTree;

template <typename Type>
class BinTreeNode
{
	friend BinaryTree<Type>;
private:
	Type element;
	BinTreeNode<Type>* left_child;
	BinTreeNode<Type>* right_child;
public:
	BinTreeNode(Type e=0, BinTreeNode<Type>* pl=NULL, BinTreeNode<Type>* pr=NULL)
	    : element(e), left_child(pl), right_child(pr) {}
	Type get_element() const { return element; }
	BinTreeNode<Type>* get_left() const { return left_child; }
	BinTreeNode<Type>* get_right() const { return right_child; }
	void update_element(Type e) { element = e; }
	void update_left(BinTreeNode<Type>* p) { left_child = p; }
	void update_right(BinTreeNode<Type>* p) { right_child = p; }
};


template <typename Type>
class BinaryTree
{
private:
	BinTreeNode<Type>* root;
public:
	BinaryTree() { root = NULL; }
	BinaryTree(const BinaryTree&);
	BinaryTree<Type>& operator=(const BinaryTree&);
	BinTreeNode<Type>* copy(BinTreeNode<Type>* p);
	void clear(BinTreeNode<Type>* p);	
	virtual ~BinaryTree();
	virtual bool is_empty() const;
	virtual int count(BinTreeNode<Type>* p) const;
	virtual BinTreeNode<Type>* get_root() const { return root; }
	virtual void pre_order(BinTreeNode<Type>* p) const;
	virtual void in_order(BinTreeNode<Type>* p) const;
	virtual void post_order(BinTreeNode<Type>* p) const;
};

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

	return this*;
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
BinTreeNode<Type>* BinaryTree<Type>::copy(BinTreeNode<Type>* p)
{
	if(p == NULL)
		return NULL;
	BinTreeNode<Type>* new_p = new BinTreeNode<Type>(p);
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
	return count(p->left_child + p->right_child + 1);
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




#endif