#ifndef _HEAP_H_INCLUDED_
#define _HEAP_H_INCLUDED_

//#include "complete_binary_tree.h"

enum heap_type {minimum, maximum};               // Notify heap's type

template <typename Type>
class Heap
{
private:
	Type* array;
	heap_type type;
	int max_size;
	int length;
	void adjust_up(int index);                   // Adjust one element's position upward
	void adjust_down(int index);                 // Adjust one element's position downward
public:
	Heap(int max_size_=99);
	Heap(Type* p, int len);                      // Create a heap from an elements' array
	//Heap(const CompleteBinTree<Type>& tree);
	Heap(const Heap& h);
	Heap<Type>& operator=(const Heap& h);
	~Heap();
	void make_minimum_tree();
	void make_maximum_tree();
	bool insert(Type);
	Type get_top() { return array[0]; }
	Type pop_top();                              // Get top element and delete it
	bool is_empty();
	bool is_full();
};


template <typename Type>
void Heap<Type>::adjust_up(int index)
{
	int father = (index+1)/2 - 1;
	if(father < 0)
		return;
	if(type == minimum)
	{
		Type tmp;
		if(array[father] > array[index])
		{
			tmp = array[father];
			array[father] = array[index];
			array[index] = tmp;
			adjust_up(father);
		}
	}
	if(type == maximum)
	{
		Type tmp;
		if(array[father] < array[index])
		{
			tmp = array[father];
			array[father] = array[index];
			array[index] = tmp;
			adjust_up(father);
		}
	}
}

template <typename Type>
void Heap<Type>::adjust_down(int index)
{
	int l_child = 2*index + 1;
	int r_child = 2*index + 2;
	if(l_child >= length)
		return;
	if(type == minimum)
	{
		int min;
		if(r_child >= length)
			min = l_child;
		else
			min = (array[l_child] < array[r_child]) ? l_child : r_child;  // Find out the smaller child
		if(array[index] > array[min])
		{
			Type tmp;
			tmp = array[min];
			array[min] = array[index];
			array[index] = tmp;
			adjust_down(min);
		}
	}
	if(type == maximum)
	{
		int max;
		if(r_child >= length)
			max = l_child;
		else
			max = (array[l_child] > array[r_child]) ? l_child : r_child;
		if(array[index] < array[max])
		{
			Type tmp;
			tmp = array[max];
			array[max] = array[index];
			array[index] = tmp;
			adjust_down(max);
		}
	}
}

template <typename Type>
Heap<Type>::Heap(int max_size_)
	: max_size(max_size_), length(0), type(minimum)
{
	array = new Type[max_size];
}

template <typename Type>
Heap<Type>::Heap(Type* p, int len)
	: max_size(len), length(len), type(minimum)
{
	array = new Type[max_size];
	for(int i=0; i<len; i++)
		array[i] = p[i];
	make_minimum_tree();
}

template <typename Type>
Heap<Type>::Heap(const Heap& h)
	: max_size(h.max_size), length(h.length), type(h.type)
{
	array = new Type[max_size];
	for(int i=0; i<length; i++)
		array[i] = h.array[i];
}

template <typename Type>
Heap<Type>& Heap<Type>::operator=(const Heap& h)
{
	delete [] array;
	max_size = h.max_size;
	length = h.length;
	type = h.type;
	array = new Type[max_size];
	for(int i=0; i<length; i++)
		array[i] = h.array[i];
}


template <typename Type>
Heap<Type>::~Heap()
{
	delete [] array;
}

template <typename Type>
void Heap<Type>::make_minimum_tree()
{
	type = minimum;
	int mid = length/2 - 1;
	for(int i=mid; i>=0; i--)
	{
		adjust_down(i);
	}
}

template <typename Type>
void Heap<Type>::make_maximum_tree()
{
	type = maximum;
	int mid = length/2 - 1;
	for(int i=mid; i>=0; i--)
	{
		adjust_down(i);
	}
}

template <typename Type>
bool Heap<Type>::insert(Type x)
{
	if(is_full())
		return false;
	array[length] = x;
	length++;
	adjust_up(length - 1);
	return true;
}

template <typename Type>
Type Heap<Type>::pop_top()
{
	if(is_empty())
		return 0;
	Type top = array[0];
	array[0] = array[length - 1];
	length--;
	adjust_down(0);
	return top;
}

template <typename Type>
bool Heap<Type>::is_empty()
{
	if(length <= 0)
		return true;
	return false;
}

template <typename Type>
bool Heap<Type>::is_full()
{
	if(length >= max_size)
		return true;
	return false;
}


#endif