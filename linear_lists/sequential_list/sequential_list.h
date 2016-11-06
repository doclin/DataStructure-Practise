#ifndef _SEQUENTIAL_LIST_H_INCLUDED_
#define _SEQUENTIAL_LIST_H_INCLUDED_

#include "../linear_list.h"
#include <iostream>
using namespace std;


template <typename Type>
class SequentialList: public LinearList<Type>
{
private:
	Type * list;                                                         // The list's first element address
	int max_size;
	int len;
public:
	SequentialList(int max_size_=999);                                    // Constructor
	SequentialList(const SequentialList& s);                             // Copy constructor
	virtual SequentialList<Type>& operator=(const SequentialList& s);
	virtual ~SequentialList();                                           // Destructor
	virtual int length() const { return len; };
	//virtual int max_length() const { return max_size; };
	virtual int index(const Type& x) const;                            
	virtual bool is_in(const Type & x) const;	
	virtual bool insert(const Type& x, int i);
	virtual bool remove(int i);
	virtual bool update(const Type& x, int i);
	virtual bool append(const Type& x);
	virtual bool is_empty() const;
	virtual bool is_full() const;
	virtual bool clear();
	virtual Type& get(int i) const { return list[i]; };                   // Need exceptions
	virtual Type& operator[](int i) const { return list[i]; };
};


template <typename Type>
SequentialList<Type>::SequentialList(int max_size_)
{
	max_size = max_size_;
	list = new Type[max_size];
	len = 0;
}

template <typename Type>
SequentialList<Type>::SequentialList(const SequentialList& s)
{
	max_size = s.max_size;
	len = s.len;
	list = new Type[max_size];                                            // Deep copy
	for(int i=0; i<len; i++)
	{
		list[i] = s.list[i];
	}
}

template <typename Type>
SequentialList<Type>& SequentialList<Type>::operator=(const SequentialList& s)
{
	delete [] list;                                                       // Deep Copy
	max_size = s.max_size;
	len = s.len;
	list = new Type[max_size];
	for(int i=0; i<len; i++)
	{
		list[i] = s.list[i];
	}
	return *this;
}

template <typename Type>
SequentialList<Type>::~SequentialList()
{
	delete [] list;
}

template <typename Type>
bool SequentialList<Type>::is_in(const Type& x) const
{
	for(int i=0; i<len; i++)
	{
		if(list[i] == x)
			return true;
	}
	return false;
}

template <typename Type>
int SequentialList<Type>::index(const Type& x) const
{
	for(int i=0; i<len; i++)
	{
		if(list[i] == x)
			return i;
	}

	return -1;
}

template <typename Type>
bool SequentialList<Type>::insert(const Type& x, int i)
{
	if(i<0 or i>len or len>=max_size)
		return false;
	
	if(i == len)
		append(x);
	else
	{
	    for(int j=len-1; j>=i; j--)
	    {
		    list[j+1] = list[j];
	    }
	    list[i] = x;
	    len++;
	}
	return true;
}

template <typename Type>
bool SequentialList<Type>::remove(int i)
{
	if(i<0 or i>=len)
		return false;
	for(int j=i; j<len-1; j++)
	{
		list[j] = list[j+1];
	}
	len--;

	return true;
}

template <typename Type>
bool SequentialList<Type>::update(const Type& x, int i)
{
	if(i<0 or i>=len)
		return false;
	list[i] = x;

	return true;
}

template <typename Type>
bool SequentialList<Type>::append(const Type& x)
{
	if(len >= max_size)
		return false;
	list[len] = x;
	len++;

	return true;
}

template <typename Type>
bool SequentialList<Type>::is_empty() const
{
	if(len == 0)
		return true;
	return false;
}

template <typename Type>
bool SequentialList<Type>::is_full() const
{
	if(len >= max_size)
		return true;
	return false;
}

template <typename Type>
bool SequentialList<Type>::clear()
{
	len = 0;                                                             // A fast way
	return true;
}


#endif