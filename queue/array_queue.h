#ifndef _ARRAY_QUEUE_H_INCLUDED_
#define _ARRAY_QUEUE_H_INCLUDED_

template <typename Type>
class ArrayQueue
{
private:
	Type* array;
	int front;
	int rear;
	int max_size;
public:
	ArrayQueue(int max_size_=999);
	ArrayQueue(const ArrayQueue&);
	ArrayQueue<Type>& operator=(const ArrayQueue&);
	~ArrayQueue();
	bool enqueue(const Type&);
	Type dequeue();
	Type get_front_element();
	bool clear();
	bool is_empty() const;
	bool is_full() const;
};


template <typename Type>
ArrayQueue<Type>::ArrayQueue(int max_size_)
	: max_size(max_size_), front(-1), rear(-1)
{
	array = new Type[max_size];
}

template <typename Type>
ArrayQueue<Type>::ArrayQueue(const ArrayQueue& aq)
{
	max_size = aq.max_size;
	array = new Type[max_size];
	for(int i=0; i<max_size; i++)
		array[i] = aq.array[i];
	front = aq.front;
	rear = aq.rear;
}

template <typename Type>
ArrayQueue<Type>& ArrayQueue<Type>::operator=(const ArrayQueue& aq)
{
	max_size = aq.max_size;
	delete [] array;
	array = new Type[max_size];
	for(int i=0; i<max_size; i++)
		array[i] = aq.array[i];
	front = aq.front;
	rear = aq.rear;

	return *this;
}

template <typename Type>
ArrayQueue<Type>::~ArrayQueue()
{
	delete [] array;
}

template <typename Type>
bool ArrayQueue<Type>::enqueue(const Type& t)
{
	if(is_full())
		return false;	
	if(is_empty())
	{
		array[0] = t;
		front = rear = 0;
	}
	else
	{
		rear = (rear+1)%max_size;
		array[rear] = t;
	}
	return true;
}

template <typename Type>
Type ArrayQueue<Type>::dequeue()
{
	
}