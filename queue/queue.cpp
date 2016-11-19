#include <iostream>
#include "queue.h"
#include "array_queue.h"

using namespace std;

int main()
{
	ArrayQueue<int> queue;
	cout << queue.is_empty() << endl;               //1
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	cout << queue.get_front_element() << endl;      //1
	cout << queue.dequeue() << endl;                //1
	cout << queue.dequeue() << endl;                //2
	cout << queue.dequeue() << endl;                //3
	cout << queue.dequeue() << endl;                //0
	cout << queue.is_empty() << endl;               //1
	queue.enqueue(1);              
	queue.clear();
	cout << queue.is_empty() << endl;               //1

	return 0;
}