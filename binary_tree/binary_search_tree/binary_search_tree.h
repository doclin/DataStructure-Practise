#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include "../binary_tree.h"

template <typename Type>
class BSTree : public BinaryTree<Type>
{
private:
	void build(BinTreeNode<Type>*);
public:
	BSTree() : BinaryTree<Type>::BinaryTree() {}
	BSTree(const Type& x) : BinaryTree<Type>::BinaryTree(x) {}
	BSTree(const BSTree<Type>& t) : BinaryTree<Type>::BinaryTree(t) {}
	BSTree(const BinaryTree<Type>&);
	BSTree(Type* p, int len);
	BSTree<Type>& operator=(const BSTree<Type>& t);
	virtual ~BSTree() {}
	virtual bool search(const Type&) const;
	virtual bool insert(const Type&);
	virtual bool remove(const Type&);
};


template <typename Type>
void BSTree<Type>::build(BinTreeNode<Type>* p)
{
	if(p != NULL)
	{
		build(p -> left_child);
		insert(p -> element);
		build(p -> right_child);
	}
}

template <typename Type>
BSTree<Type>::BSTree(const BinaryTree<Type>& t)
{
	build(t.root);
}

template <typename Type>
BSTree<Type>::BSTree(Type* p, int len)
{
	for(int i=0; i<len; i++)
		insert(p[i]);
}

template <typename Type>
BSTree<Type>& BSTree<Type>::operator=(const BSTree<Type>& t)
{ 
	BinaryTree<Type>::operator=(t);
	return *this;
}

template <typename Type>
bool BSTree<Type>::search(const Type& t) const
{
	BinTreeNode<Type>* current = BinaryTree<Type>::root;
	while(current != NULL)
	{
		if(t == current->element)
			return true;
		else if(t > current->element)
			current = current -> right_child;
		else if(t < current->element)
			current = current -> left_child;
	}
	return false;
}

template <typename Type>
bool BSTree<Type>::insert(const Type& t)
{
	if(BinaryTree<Type>::root == NULL)
		BinaryTree<Type>::root = new BinTreeNode(t);
	return true;	
	BinTreeNode<Type>* current = BinaryTree<Type>::root;
	while(current != NULL)
	{
		if(t == current->element)
			return false;
		else if(t > current->element)
		{
			if(current->right_child != NULL)
				current = current -> right_child;
			else
			{
				current -> right_child = new BinTreeNode(t);
				return true;
			}
		}
		else if(t < current->element)
		{
			if(current->left_child != NULL)
				current = current -> left_child;
			else
			{
				current -> left_child = new BinTreeNode(t);
				return true;
			}
		}
	}
}

template <typename Type>
bool BSTree<Type>::remove(const Type& t)
{
	BinTreeNode<Type>* current = BinaryTree<Type>::root;
	BinTreeNode<Type>*& parent_pointer = BinaryTree<Type>::root;
	while(current != NULL)
	{
		if(t == current->element)
		{
			if(current->right_child == NULL and current->left_child == NULL)
			{
				parent_pointer = NULL;
				delete current;				
			}
			if(current->right_child != NULL and current->left_child == NULL)
			{
				parent_pointer = current -> right_child;
				delete current;
			}
			if(current->right_child == NULL and current->left_child != NULL)
			{
				parent_pointer = current -> left_child;
				delete current;
			}
			if(current->right_child != NULL and current->left_child != NULL)
			{
				BinTreeNode<Type>* p = current -> right_child;
				BinTreeNode<Type>* parent = current;
				while(p->left_child != NULL)
				{
					parent = p;
					p = p -> left_child;
				}
				Type tmp = p -> element;
				p -> element = current -> element;
				current -> element = tmp;
				parent -> left_child = p -> right_child;
				delete p;
			}
			
			return true;
		}
		else if(t > current->element)
		{
			parent_pointer = current -> right_child;
			current = current -> right_child;
		}
		else if(t < current->element)
		{
			parent_pointer = current -> left_child;
			current = current -> left_child;
		}
	}
	return false;
}


#endif