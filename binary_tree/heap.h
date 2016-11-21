#ifndef _HEAP_H_INCLUDED_
#define _HEAP_H_INCLUDED_

#include "complete_binary_tree.h"

enum heap_type {minimum, maximum}

template <typename Type>
class Heap
{
private:
	Type* array;
	heap_type type;
	int max_size;
	int length;
public:
	Heap(int max_size_=99);
	Heap(Type* p, int len);
	//Heap(const CompleteBinTree<Type>& tree);
	Heap(const Heap& h);
	Heap<Type>& operator=(const Heap& h);
	~Heap();
	void make_minimum_tree();
	void make_maximum_tree();
	void insert(Type);
	Type get_top();
	bool delete_top();
};


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








#endif