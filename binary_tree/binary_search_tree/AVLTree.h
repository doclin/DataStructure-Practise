#ifndef _AVLTREE_H_INCLUDED_
#define _AVLTREE_H_INCLUDED_

#include "binary_search_tree.h"

template <typename Type>
class AVLTree : public BSTree<Type>
{
private:
	//void build(BinTreeNode<Type>*);
	//void balance(BinTreeNode<Type>*& p);
	void l_rotation(BinTreeNode<Type>*& p);
	void r_rotation(BinTreeNode<Type>*& p);
	int height(BinTreeNode<Type>*);
	int judge(BinTreeNode<Type>*);
	bool insert(BinTreeNode<Type>*& p, const Type& t, bool& flag);
	bool remove(BinTreeNode<Type>* p, const Type& t);
public:
	AVLTree() : BSTree<Type>::BSTree() {}
	AVLTree(const Type& x) : BSTree<Type>::BSTree(x) {}
	AVLTree(const AVLTree<Type>& t) : BSTree<Type>::BSTree(t) {}

	//AVLTree(const BSTree<Type>& t);
	//AVLTree(const BinaryTree<Type>& t);

	AVLTree<Type>& operator=(const AVLTree<Type>& t);
	virtual ~AVLTree() {}
	virtual bool insert(const Type&);
	virtual bool remove(const Type&);
};


template <typename Type>
void AVLTree<Type>::l_rotation(BinTreeNode<Type>*& p)
{
	int n = judge(p->right_child);
	BinTreeNode<Type>* tmp = p;
	if(n > 0)
	{
		p = p -> right_child;
		tmp -> right_child = p -> left_child;
		p -> left_child = tmp;
	}
	if(n < 0)
	{
		p = p -> right_child -> left_child;
		tmp -> right_child -> left_child = p -> right_child;
		p -> right_child = tmp -> right_child;
		tmp -> right_child = p -> left_child;
		p -> left_child = tmp;
	}
}

template <typename Type>
void AVLTree<Type>::r_rotation(BinTreeNode<Type>*& p)
{
	int n = judge(p->left_child);
	BinTreeNode<Type>* tmp = p;
	if(n > 0)
	{
		p = p -> left_child -> right_child;
		tmp -> left_child -> right_child = p -> left_child;
		p -> left_child = tmp -> left_child;
		tmp -> left_child = p -> right_child;
		p -> right_child = tmp;
	}
	if(n < 0)
	{
		p = p -> left_child;
		tmp -> left_child = p -> right_child;
		p -> right_child = tmp;
	}
}

template <typename Type>
int AVLTree<Type>::height(BinTreeNode<Type>* p)
{
	if(p == NULL)
		return 0;
	return 1 + height(p->left_child) + height(p->right_child);
}

template <typename Type>
int AVLTree<Type>::judge(BinTreeNode<Type>* p)
{
	return height(p->right_child) - height(p->left_child);
}

template <typename Type>
bool AVLTree<Type>::insert(BinTreeNode<Type>*& p, const Type& t, bool& flag)
{
	if(p == NULL)
	{
		p = new BinTreeNode<Type>(t);
		flag = false;
		return true;
	}
	else if(t == p->element)
		return false;

	else if(t > p->element)
	{
		if(!insert(p->right_child, t, flag))
			return false;
		if(!flag)
		{
			if(judge(p) == 2)
			{
				l_rotation(p);
				flag = true;
			}
		}
		return true;
	}
	else if(t < p->element)
	{
		if(!insert(p->left_child, t, flag))
			return false;
		if(!flag)
		{
			if(judge(p) == -2)
			{
				r_rotation(p);
				flag = true;
			}
		}
		return true;		
	}
}

template <typename Type>
bool AVLTree<Type>::remove(BinTreeNode<Type>*& p, const Type& t, )
{
	if(p == NULL)
		return false;
	else if(t > p->element)
	{
		remove(p -> right_child);
	}
	else if(t < p->element)
	{
		remove(p -> left_child);
	}
	else if(t == p->element)
	{
		if(p->right_child == NULL and p->left_child == NULL)
		{
			*parent_pointer = NULL;
			delete p;				
		}
		else if(p->right_child != NULL and p->left_child == NULL)
		{
			*parent_pointer = p -> right_child;
			delete p;
		}
		else if(p->right_child == NULL and p->left_child != NULL)
		{
			*parent_pointer = p -> left_child;
			delete p;
		}
		else if(p->right_child != NULL and p->left_child != NULL)
		{
			BinTreeNode<Type>* p = p -> right_child;
			BinTreeNode<Type>* parent = p;
			while(p->left_child != NULL)
			{
				parent = p;
				p = p -> left_child;
			}
			Type tmp = p -> element;
			p -> element = p -> element;
			p -> element = tmp;
			parent -> left_child = p -> right_child;
			delete p;
		}
	}







	


	if(p == NULL)
	{
		p = new BinTreeNode<Type>(t);
		flag = false;
		return true;
	}
	else if(t == p->element)
		return false;

	else if(t > p->element)
	{
		if(!insert(p->right_child, t, flag))
			return false;
		if(!flag)
		{
			if(judge(p) == 2)
			{
				l_rotation(p);
				flag = true;
			}
		}
		return true;
	}
	else if(t < p->element)
	{
		if(!insert(p->left_child, t, flag))
			return false;
		if(!flag)
		{
			if(judge(p) == -2)
			{
				r_rotation(p);
				flag = true;
			}
		}
		return true;		
	}




}





template <typename Type>
AVLTree<Type>& AVLTree<Type>::operator=(const AVLTree<Type>& t)
{
	BSTree<Type>::operator=(t);
	return *this;
}

template <typename Type>
bool AVLTree<Type>::insert(const Type& t)
{
	bool flag = true;
	return insert(this -> root, t, flag);
}

template <typename Type>
bool AVLTree<Type>::remove(const Type& t)
{
	return remove(this -> root, t,);
}







#endif