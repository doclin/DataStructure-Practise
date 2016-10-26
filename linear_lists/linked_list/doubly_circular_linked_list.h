#ifndef _DOUBLY_CIRCULAR_LINKED_LIST_H_INCLUDED_
#define _DOUBLY_CIRCULAR_LINKED_LIST_H_INCLUDED_

#include <iostream>
#include "linear_list.h"

template <typename Type> class DBCLinkedList;                              // Declare at beginning, not with :public.

template <typename Type>
class DBNode
{
	friend DBCLinkedList<Type>;
private:
	Type element;
	DBNode<Type>* pointer_to_next;
	DBNode<Type>* pointer_to_prior;
	DBNode(Type e=0, DBNode<Type>* pl=NULL, DBNode<Type>* pr=NULL): 
	    element(e), pointer_to_prior(pl), pointer_to_next(pr) {}
};


template <typename Type>
class DBCLinkedList: public LinearList<Type>
{
private:
	DBNode<Type>* first_p;                                                 // The first element's address
	DBNode<Type>* last_p;                                                  // The last element's address
	int len;                                                               // Pay attention when len = 0
	//int max_size;
public:
	DBCLinkedList();                                                       // TODO: when header is mem, can get adderss?
	DBCLinkedList(const DBCLinkedList&);
	virtual DBCLinkedList<Type>& operator=(const DBCLinkedList&);
	virtual ~DBCLinkedList();
	virtual int length() const { return len; }
	virtual int index(const Type&) const;
	virtual bool is_in(const Type&) const;
	virtual bool insert(const Type&, int);
	virtual bool remove(int);
	virtual bool append(const Type&);
	virtual bool update(const Type&, int);
	virtual bool is_empty() const;
	virtual bool is_full() const;
	virtual bool clear();
	virtual Type& get(int) const;
	virtual Type& operator[](int) const;
};


template <typename Type>
DBCLinkedList<Type>::DBCLinkedList()
    : len(0)
{
	first_p = new DBNode<Type>();                                           // Two dummy nodes
	last_p = new DBNode<Type>();
	first_p -> pointer_to_prior = first_p -> pointer_to_next = last_p;
	last_p -> pointer_to_next = last_p -> pointer_to_prior = first_p;
}

template <typename Type>
DBCLinkedList<Type>::DBCLinkedList(const DBCLinkedList& l)
{
	//max_size = l.max_size;
	len = l.len;
	first_p = new DBNode<Type>();
	last_p = new DBNode<Type>();
	first_p -> pointer_to_prior = first_p -> pointer_to_next = last_p;
	last_p -> pointer_to_next = last_p -> pointer_to_prior = first_p;
	DBNode<Type>* tem_p_original = l.first_p;
	DBNode<Type>* tem_p_new = first_p;
	while(tem_p_original->pointer_to_next != l.last_p)
	{
		tem_p_new -> pointer_to_next = new DBNode<Type>(*(tem_p_original -> pointer_to_next));
		tem_p_new -> pointer_to_next -> pointer_to_prior = tem_p_new;
		tem_p_original = tem_p_original -> pointer_to_next;
		tem_p_new = tem_p_new -> pointer_to_next;
	}
	tem_p_new -> pointer_to_next = last_p;
	last_p -> pointer_to_prior = tem_p_new;
}

template <typename Type>
DBCLinkedList<Type>& DBCLinkedList<Type>::operator=(const DBCLinkedList& l)
{
	clear();
	len = l.len;
	DBNode<Type>* tem_p_original = l.first_p;
	DBNode<Type>* tem_p_new = first_p;
	while(tem_p_original->pointer_to_next != l.last_p)
	{
		tem_p_new -> pointer_to_next = new DBNode<Type>(*(tem_p_original -> pointer_to_next));
		tem_p_new -> pointer_to_next -> pointer_to_prior = tem_p_new;
		tem_p_original = tem_p_original -> pointer_to_next;
		tem_p_new = tem_p_new -> pointer_to_next;
	}
	tem_p_new -> pointer_to_next = last_p;
	last_p -> pointer_to_prior = tem_p_new;
}

template <typename Type>
DBCLinkedList<Type>::~DBCLinkedList()
{
	DBNode<Type>* curr_p = first_p;
	DBNode<Type>* tmp_p = first_p;
	while(curr_p != last_p)
	{
		tmp_p = curr_p -> pointer_to_next;
		delete curr_p;
	    curr_p = tmp_p;
	}
	delete last_p;
}

template <typename Type>
int DBCLinkedList<Type>::index(const Type& x) const
{
	DBNode<Type>* curr_p = first_p -> pointer_to_next;
	int i = 0;
	while(curr_p != last_p)
	{
		if(curr_p->element == x)
			return i;
		curr_p = curr_p -> pointer_to_next;
		i++;
	}
	return -1;
}

template <typename Type>
bool DBCLinkedList<Type>::is_in(const Type& x) const
{
	DBNode<Type>* curr_p = first_p -> pointer_to_next;
	while(curr_p != last_p)
	{
		if(curr_p->element == x)
			return true;
		curr_p = curr_p -> pointer_to_next;
	}
	return false;
}

template <typename Type>
bool DBCLinkedList<Type>::insert(const Type& x, int i)
{
	if(i<0 or i>len)
		return false;
	DBNode<Type>* curr_p = first_p -> pointer_to_next;
	for(int j=0; j<i; j++)
	{
		curr_p = curr_p -> pointer_to_next;
	}
	curr_p -> pointer_to_prior -> pointer_to_next = new DBNode<Type>(x, curr_p->pointer_to_prior, curr_p);
	curr_p -> pointer_to_prior = curr_p -> pointer_to_prior -> pointer_to_next;
	len++;
	return true;
}

template <typename Type>
bool DBCLinkedList<Type>::remove(int i)
{
	if(i<0 or i>=len)
		return false;
	DBNode<Type>* curr_p = first_p -> pointer_to_next;
	for(int j=0; j<i; j++)
	{
		curr_p = curr_p -> pointer_to_next;
	}
	curr_p -> pointer_to_prior -> pointer_to_next = curr_p -> pointer_to_next;
	curr_p -> pointer_to_next -> pointer_to_prior = curr_p -> pointer_to_prior;
	delete curr_p;
	len--;
	return true;
}

template <typename Type>
bool DBCLinkedList<Type>::append(const Type& x)
{
	DBNode<Type>* p = last_p -> pointer_to_prior;
	p -> pointer_to_next = last_p -> pointer_to_prior = new DBNode<Type>(x, p, last_p);
	len++;
	return true;
}

template <typename Type>
bool DBCLinkedList<Type>::update(const Type& x, int i)
{
	if(i<0 or i>=len)
		return false;
	DBNode<Type>* curr_p = first_p -> pointer_to_next;
	for(int j=0; j<i; j++)
		curr_p = curr_p -> pointer_to_next;
	curr_p -> element = x;
	return true;
}

template <typename Type>
bool DBCLinkedList<Type>::is_empty() const
{
	if(len == 0)
		return true;
	return false;
}

template <typename Type>
bool DBCLinkedList<Type>::is_full() const
{
	//if(len >= max_size)
	//	return true;
	return false;
}

template <typename Type>
bool DBCLinkedList<Type>::clear()
{
	DBNode<Type>* curr_p = first_p -> pointer_to_next;
	while(curr_p != last_p)
	{
		curr_p = curr_p -> pointer_to_next;
		delete curr_p -> pointer_to_prior;
	}
	len = 0;
	return true;
}

template <typename Type>
Type& DBCLinkedList<Type>::get(int i) const
{
	DBNode<Type>* curr_p = first_p -> pointer_to_next;
	for(int j=0; j<i; j++)
		curr_p = curr_p -> pointer_to_next;
	return curr_p -> element;
}

template <typename Type>
Type& DBCLinkedList<Type>::operator[](int i) const
{
	DBNode<Type>* curr_p = first_p -> pointer_to_next;
	for(int j=0; j<i; j++)
		curr_p = curr_p -> pointer_to_next;
	return curr_p -> element;
}

#endif