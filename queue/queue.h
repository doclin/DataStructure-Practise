#ifndef _QUEUE_H_INCLUDED_
#define _QUEUE_H_INCLUDED_
#include "../linear_lists/linked_list/linked_list.h"

template <typename Type>
class Queue
{
private:
	LinkedList<Type> list;
public:
	void enqueue(const Type&);
	Type dequeue();
	Type get_front_element();
	bool clear();
	bool is_empty() const;
};


template <typename Type>
void Queue<Type>::enqueue(const Type& t)
{
	list.append(t);
}

template <typename Type>
Type Queue<Type>::dequeue()
{
	if(list.is_empty())
		return 0;
	Type value = list[0];
	list.remove(0);
	return value;
}

template <typename Type>
Type Queue<Type>::get_front_element()
{
	if(list.is_empty())
		return 0;
	Type value = list[0];
	return value;	
}

template <typename Type>
bool Queue<Type>::clear()
{
	return list.clear();
}

template <typename Type>
bool Queue<Type>::is_empty() const
{
	return list.is_empty();
}




#endif