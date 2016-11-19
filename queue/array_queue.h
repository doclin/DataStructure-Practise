#ifndef _ARRAY_QUEUE_H_INCLUDED_
#define _ARRAY_QUEUE_H_INCLUDED_

template <typename Type>
class ArrayQueue                                        // Queue implemented by array
{
private:
	Type* array;
	int front;                                          // The first element in queue
	int rear;                                           // The last one in queue
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
	: max_size(max_size_), front(-1), rear(-1)           // When front==-1 and rear==-1, queue is empty
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
	if(is_empty())
		return 0;
	int tmp = front;
	if(rear == front)                                   // When the last element leaves queue
		front = rear = -1;
	else
		front = (front+1)%max_size;
	return array[tmp];
}

template <typename Type>
Type ArrayQueue<Type>::get_front_element()
{
	if(is_empty())
		return 0;
	return array[front];
}

template <typename Type>
bool ArrayQueue<Type>::clear()
{
	front = rear = -1;
	return true;
}

template <typename Type>
bool ArrayQueue<Type>::is_empty() const
{
	if(front==-1 and rear==-1)
		return true;
	return false;
}

template <typename Type>
bool ArrayQueue<Type>::is_full() const
{
	int next = (rear+1)%max_size;
	if(next == front)
		return true;
	return false;
}

#endif