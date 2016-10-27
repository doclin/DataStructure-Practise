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
	Stack(Type e=0, Node<Type>* pl=NULL, Node<Type>* pr=NULL): element(e), pointer_to_prior(pl), pointer_to_next(pr) {}
}

template <typename Type>
class Stack
{
private:
	Node<Type>* stack_p;
	Node<Type>* top;
public:
	Stack() {}
	Stack(const Stack&);
	Stack<Type>& operator=(const Stack&);
}


#endif