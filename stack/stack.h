#ifndef _STACK_H_INCLUDED_
#define _STACK_H_INCLUDED_

template <typename Type> class Stack;

template <typename Type>
class Node
{
	friend class Stack<Type>;
private:
	Type element;
	Node<Type>* pointer_to_next;
	Node<Type>* pointer_to_prior;
	Node(Type e=0, Node<Type>* pl=NULL, Node<Type>* pr=NULL) 
	    : element(e), pointer_to_prior(pl), pointer_to_next(pr) {}
};

template <typename Type>
class Stack
{
private:
	Node<Type>* stack_p;
	Node<Type>* top;
public:
	Stack();
	~Stack();
	Stack(const Stack&);
	Stack<Type>& operator=(const Stack&);
	bool push(const Type&);
	Type get_top_element();
	Type pop();
	bool clear();
	bool is_empty() const;
};

template <typename Type>
Stack<Type>::Stack()
{
	stack_p = top = new Node<Type>();
}

template <typename Type>
Stack<Type>::~Stack()
{
	clear();
	delete stack_p;
}

template <typename Type>
Stack<Type>::Stack(const Stack& s)
{
	stack_p = top = new Node<Type>();
	Node<Type>* p_original = s.stack_p;
	while(p_original != s.top)
	{
		top -> pointer_to_next = new Node<Type>(*(p_original -> pointer_to_next));
		top -> pointer_to_next -> pointer_to_prior = top;
		top = top -> pointer_to_next;
		p_original = p_original -> pointer_to_next;
	}
}

template <typename Type>
Stack<Type>& Stack<Type>::operator=(const Stack& s)
{
	clear();
	Node<Type>* p_original = s.stack_p;
	while(p_original != s.top)
	{
		top -> pointer_to_next = new Node<Type>(*(p_original -> pointer_to_next));
		top -> pointer_to_next -> pointer_to_prior = top;
		top = top -> pointer_to_next;
		p_original = p_original -> pointer_to_next;
	}	
}

template <typename Type>
bool Stack<Type>::push(const Type& x)
{
	top -> pointer_to_next = new Node<Type>(x, top, NULL);
	top = top -> pointer_to_next;
	return true;
}

template <typename Type>
Type Stack<Type>::pop()
{
	Type value = top -> element;
	if(stack_p != top)
	{
	    top = top -> pointer_to_prior;
	    delete (top -> pointer_to_next);		
	}
	return value;
}

template <typename Type>
Type Stack<Type>::get_top_element()
{
	return (top -> element);
}

template <typename Type>
bool Stack<Type>::clear()
{
	while(top != stack_p)
	{
		top = top -> pointer_to_prior;
		delete (top -> pointer_to_next);
	}

}

template <typename Type>
bool Stack<Type>::is_empty() const
{
	if(top == stack_p)
		return true;
	return false;
}


#endif