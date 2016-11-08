#ifndef _LINKED_LIST_H_INCLUDED_
#define _LINKED_LIST_H_INCLUDED_

#include <iostream>
#include "../linear_list.h"

template <typename Type> class LinkedList;                         // Declare at beginning, not with :public.

template <typename Type>
class Node
{
	friend class LinkedList<Type>;
private:
	Type element;
	Node<Type>* pointer_to_next;
	Node(Type e=0, Node<Type>* p=NULL): element(e), pointer_to_next(p) {}
};


template <typename Type>
class LinkedList: public LinearList<Type>
{
private:
	Node<Type>* first_p;                                           // The first element's address
	Node<Type>* last_p;                                            // The last element's address
	int len;                                                       // Pay attention when len = 0
	int max_size;
public:
	LinkedList(int max_size_=100): first_p(NULL), last_p(NULL), len(0), max_size(max_size_) {} // TODO: when header is mem, can get adderss?
	LinkedList(const LinkedList&);
	virtual LinkedList<Type>& operator=(const LinkedList&);
	virtual ~LinkedList();
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
LinkedList<Type>::LinkedList(const LinkedList& l)
{
	max_size = l.max_size;
	len = l.len;
	first_p = NULL;
	last_p = NULL;
	if(len != 0)                                                           // When len==0, above things are enough
	{
	    first_p = new Node<Type>(*(l.first_p));                            // Doesn't matter whether it is deep copy or not
	    Node<Type>* tem_p_original = l.first_p;
	    Node<Type>* tem_p_new = first_p;
	    while(tem_p_original->pointer_to_next != NULL)
	    {
	        tem_p_new -> pointer_to_next = new Node<Type>(*(tem_p_original -> pointer_to_next));
		    tem_p_original = tem_p_original -> pointer_to_next;
		    tem_p_new = tem_p_new -> pointer_to_next;
	    }
	    last_p = tem_p_new;
    }
}

template <typename Type>
LinkedList<Type>& LinkedList<Type>::operator=(const LinkedList& l)
{
	clear();                                                               // clear original nodes
	max_size = l.max_size;
	len = l.len;
	first_p = NULL;
	last_p = NULL;
	if(len != 0)                                                           // When len==0, above things is enough
	{
	    first_p = new Node<Type>(*(l.first_p));                            // Doesn't matter whether it is deep copy or not
	    Node<Type>* tem_p_original = l.first_p;
	    Node<Type>* tem_p_new = first_p;
	    while(tem_p_original->pointer_to_next != NULL)
	    {
	        tem_p_new -> pointer_to_next = new Node<Type>(*(tem_p_original -> pointer_to_next));
		    tem_p_original = tem_p_original -> pointer_to_next;
		    tem_p_new = tem_p_new -> pointer_to_next;
	    }
	    last_p = tem_p_new;
    }	
    return *this;
}

template <typename Type>
LinkedList<Type>::~LinkedList()
{
	// Because clear() is a virtual function, we shouldn't call it in destructor function.
	Node<Type>* curr_p = first_p;
	Node<Type>* tmp_p = NULL;
	while(curr_p != NULL)
	{
		tmp_p = curr_p -> pointer_to_next;
		delete curr_p;
		curr_p = tmp_p;
	}	
}

template <typename Type>
int LinkedList<Type>::index(const Type& x) const
{
	Node<Type>* curr_p = first_p;
	int i = 0;
	while(curr_p != NULL)
	{
		if(curr_p->element == x)
			return i;
		i++;
		curr_p = curr_p -> pointer_to_next;
	}
	return -1;                                                             // Fail
}

template <typename Type>
bool LinkedList<Type>::is_in(const Type& x) const
{
	Node<Type>* curr_p = first_p;
	while(curr_p != NULL)
	{
		if(curr_p->element == x)
			return true;
		curr_p = curr_p -> pointer_to_next;
	}
	return false;
}

template <typename Type>
bool LinkedList<Type>::insert(const Type& x, int i)
{
	if(i<0 or i>len or len>=max_size)
		return false;

	if(i == len)
		append(x);
	else
	{
		Node<Type>* curr_p = first_p;
		Node<Type>* pre_p = NULL;
		for (int j=0; j<i; j++)
		{
			pre_p = curr_p;
			curr_p = curr_p -> pointer_to_next;
		}
		if(i != 0)
		    pre_p -> pointer_to_next = new Node<Type>(x, curr_p);
		else
			first_p = new Node<Type>(x, first_p);
		len++;
	}
	return true;
}

template <typename Type>
bool LinkedList<Type>::remove(int i)
{
	if(i<0 or i>=len)
		return false;
	Node<Type>* curr_p = first_p;
	Node<Type>* pre_p = NULL;                                                  // Store the prior node of the current one
	for(int j=0; j<i; j++ )                                                    // Move pointers to correct place
	{
		pre_p = curr_p;
		curr_p = curr_p -> pointer_to_next;
	}

	if(i != 0)                                                                 // Deal with head-node case
	    pre_p -> pointer_to_next = curr_p -> pointer_to_next;
	else
		first_p = first_p -> pointer_to_next;
	if(i ==  len-1)                                                            // Deal with last-node case
		last_p = pre_p;
	delete curr_p;
	len--;
	return true;
}

template <typename Type>
bool LinkedList<Type>::append(const Type& x)
{
	if(len >= max_size)
		return false;
	if(len == 0)                                                                       
		first_p = last_p = new Node<Type>(x, NULL);
	else
		last_p = last_p -> pointer_to_next = new Node<Type>(x, NULL);
	len++;
	return true;
}

template <typename Type>
bool LinkedList<Type>::update(const Type& x, int i)
{
	if(i<0 or i>=len)
		return false;
	Node<Type>* curr_p = first_p;
	for(int j=0; j<i; j++)
		curr_p = curr_p -> pointer_to_next;
	curr_p -> element = x;
	return true;
}

template <typename Type>
bool LinkedList<Type>::is_empty() const
{
	if(len == 0)
		return true;
	return false;
}

template <typename Type>
bool LinkedList<Type>::is_full() const
{
	if(len >= max_size)
		return true;
	return false;
}

template <typename Type>
bool LinkedList<Type>::clear()
{
	Node<Type>* curr_p = first_p;
	Node<Type>* tmp_p = NULL;
	while(curr_p != NULL)
	{
		tmp_p = curr_p -> pointer_to_next;
		delete curr_p;
		curr_p = tmp_p;
	}
	first_p = last_p = NULL;
	len = 0;
	return true;
}

template <typename Type>
Type& LinkedList<Type>::get(int i) const
{
	if(i<0 or i>=len)                                                             // A problem
		;//return 0;
	Node<Type>* curr_p = first_p;
	for(int j=0; j<i; j++)
		curr_p = curr_p -> pointer_to_next;
	return curr_p -> element;
}

template <typename Type>
Type& LinkedList<Type>::operator[](int i) const
{
	if(i<0 or i>=len)                                                             // A problem
		;//return 0;
	Node<Type>* curr_p = first_p;
	for(int j=0; j<i; j++)
		curr_p = curr_p -> pointer_to_next;
	return curr_p -> element;	
}





#endif