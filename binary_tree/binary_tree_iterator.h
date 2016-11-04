#ifndef _BINARY_TREE_ITERATOR_INCLUDED_
#define _BINARY_TREE_ITERATOR_INCLUDED_
#include "binary_tree.h"
#include "../stack/stack.h"
#include "../queue/queue.h"

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
	PreOrderIterator(BinaryTree<Type>& bt): BaseIterator<Type>::BaseIterator(bt) {}
	virtual BinTreeNode<Type>* first();
	virtual BinTreeNode<Type>* next();
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p));
};


template <typename Type>
class InOrderIterator : public BaseIterator<Type>
{
	Stack<BinTreeNode<Type>*> stack;
public:
	InOrderIterator(BinaryTree<Type>& bt): BaseIterator<Type>::BaseIterator(bt) {}
	virtual BinTreeNode<Type>* first();
	virtual BinTreeNode<Type>* next();
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p));
};


template <typename Type>
class PostOrderIterator : public BaseIterator<Type>
{
	Stack<BinTreeNode<Type>*> stack;
	BinTreeNode<Type>* pre;
public:
	PostOrderIterator(BinaryTree<Type>& bt): BaseIterator<Type>::BaseIterator(bt), pre(NULL) {}
	virtual BinTreeNode<Type>* first();
	virtual BinTreeNode<Type>* next();
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p));
};


template <typename Type>
class LevelOrderIterator : public BaseIterator<Type>
{
	Queue<BinTreeNode<Type>*> queue;
public:
	LevelOrderIterator(BinaryTree<Type>& bt): BaseIterator<Type>::BaseIterator(bt) {}
	virtual BinTreeNode<Type>* first();
	virtual BinTreeNode<Type>* next();
	virtual void traverse(void (* func)(BinTreeNode<Type>* node_p));
};


template <typename Type>
BinTreeNode<Type>* PreOrderIterator<Type>::first()
{
	BaseIterator<Type>::current = BaseIterator<Type>::tree.get_root();
	if(BaseIterator<Type>::current != NULL)	
	{
		stack.push(BaseIterator<Type>::current);
		BaseIterator<Type>::current = BaseIterator<Type>::current -> left_child;
	}
	return BaseIterator<Type>::tree.get_root();
}

template <typename Type>
BinTreeNode<Type>* PreOrderIterator<Type>::next()
{
	while(BaseIterator<Type>::current == NULL and !stack.is_empty())
	{
		BaseIterator<Type>::current = stack.pop();
		BaseIterator<Type>::current = BaseIterator<Type>::current -> right_child;
	}
	if(BaseIterator<Type>::current==NULL and stack.is_empty())
		return first();
	stack.push(BaseIterator<Type>::current);
	BaseIterator<Type>::current = BaseIterator<Type>::current -> left_child;
	return stack.get_top_element();
}

template <typename Type>
void PreOrderIterator<Type>::traverse(void (* func)(BinTreeNode<Type>* node_p))
{
	Stack<BinTreeNode<Type>*> s; //
	BinTreeNode<Type>* curr_p = BaseIterator<Type>::tree.get_root();
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
BinTreeNode<Type>* InOrderIterator<Type>::first()
{
	BaseIterator<Type>::current = BaseIterator<Type>::tree.get_root();
	if(BaseIterator<Type>::current==NULL)
		return BaseIterator<Type>::current;
	while(BaseIterator<Type>::current != NULL)
	{
		stack.push(BaseIterator<Type>::current);
		BaseIterator<Type>::current = BaseIterator<Type>::current -> left_child;
	}
	BaseIterator<Type>::current = stack.get_top_element();
	BaseIterator<Type>::current = BaseIterator<Type>::current -> right_child;
	return stack.pop();
}

template <typename Type>
BinTreeNode<Type>* InOrderIterator<Type>::next()
{
	while(BaseIterator<Type>::current != NULL)
	{
		stack.push(BaseIterator<Type>::current);
		BaseIterator<Type>::current = BaseIterator<Type>::current -> left_child;
	}
	if(BaseIterator<Type>::current==NULL and stack.is_empty())
		return first();
	BaseIterator<Type>::current = stack.get_top_element();
	BaseIterator<Type>::current = BaseIterator<Type>::current -> right_child;
	return stack.pop();
}

template <typename Type>
void InOrderIterator<Type>::traverse(void (* func)(BinTreeNode<Type>* node_p))
{
	Stack<BinTreeNode<Type>*> s;
	BinTreeNode<Type>* curr_p = BaseIterator<Type>::tree.get_root();
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
BinTreeNode<Type>* PostOrderIterator<Type>::first()
{
	BaseIterator<Type>::current = BaseIterator<Type>::tree.get_root();
	if(BaseIterator<Type>::current == NULL)
		return BaseIterator<Type>::current;
	while(true)
	{
		while(BaseIterator<Type>::current != NULL)
		{
			stack.push(BaseIterator<Type>::current);
			BaseIterator<Type>::current = BaseIterator<Type>::current -> left_child;
		}
		BaseIterator<Type>::current = stack.get_top_element();
		if(BaseIterator<Type>::current->right_child == NULL or BaseIterator<Type>::current->right_child == pre)
			break;
		else
			BaseIterator<Type>::current = BaseIterator<Type>::current -> right_child;
	}
	pre = BaseIterator<Type>::current;
	stack.pop();
	BaseIterator<Type>::current = NULL;
	return pre;
}

template <typename Type>
BinTreeNode<Type>* PostOrderIterator<Type>::next()
{
	if(BaseIterator<Type>::current==NULL and stack.is_empty())
		return first();
	while(true)
	{
		while(BaseIterator<Type>::current != NULL)
		{
			stack.push(BaseIterator<Type>::current);
			BaseIterator<Type>::current = BaseIterator<Type>::current -> left_child;
		}
		BaseIterator<Type>::current = stack.get_top_element();
		if(BaseIterator<Type>::current->right_child == NULL or BaseIterator<Type>::current->right_child == pre)
			break;
		else
			BaseIterator<Type>::current = BaseIterator<Type>::current -> right_child;
	}
	pre = BaseIterator<Type>::current;
	stack.pop();
	BaseIterator<Type>::current = NULL;
	return pre;
}

template <typename Type>
void PostOrderIterator<Type>::traverse(void (* func)(BinTreeNode<Type>* node_p))
{
	Stack<BinTreeNode<Type>*> s;
	BinTreeNode<Type>* curr_p = BaseIterator<Type>::tree.get_root();
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

template <typename Type>
BinTreeNode<Type>* LevelOrderIterator<Type>::first()
{
	BaseIterator<Type>::current = BaseIterator<Type>::tree.get_root();
	if(BaseIterator<Type>::current != NULL)
	{
		if(BaseIterator<Type>::current -> left_child)
			queue.enqueue(BaseIterator<Type>::current -> left_child);
		if(BaseIterator<Type>::current -> right_child)
			queue.enqueue(BaseIterator<Type>::current -> right_child);
	}
	return BaseIterator<Type>::current;
}

template <typename Type>
BinTreeNode<Type>* LevelOrderIterator<Type>::next()
{
	if(queue.is_empty())
		return first();
	BaseIterator<Type>::current = queue.dequeue();
	if(BaseIterator<Type>::current -> left_child)
		queue.enqueue(BaseIterator<Type>::current -> left_child);
	if(BaseIterator<Type>::current -> right_child)
		queue.enqueue(BaseIterator<Type>::current -> right_child);
	return BaseIterator<Type>::current;
}

template <typename Type>
void LevelOrderIterator<Type>::traverse(void (* func)(BinTreeNode<Type>* node_p))
{
	Queue<BinTreeNode<Type>*> q;
	BinTreeNode<Type>* curr_p = BaseIterator<Type>::tree.get_root();
	if(curr_p != NULL)
		q.enqueue(curr_p);
	while(!q.is_empty())
	{
		curr_p = q.dequeue();
		func(curr_p);
		if(curr_p -> left_child)
			q.enqueue(curr_p->left_child);
		if(curr_p -> right_child)
			q.enqueue(curr_p->right_child);
	}
}





#endif