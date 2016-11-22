#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
	int a[7] = {1, 3, 5, 2, 4, 3, 9};
	Heap<int> heap1(a, 7);
	cout << heap1.get_top() << endl;           // 1
	heap1.make_maximum_tree();
	cout << heap1.get_top() << endl;           // 9
	cout << heap1.insert(7) << endl;           // 0
	cout << heap1.is_full() << endl;           // 1
	cout << heap1.pop_top() << endl;           // 9
	cout << heap1.pop_top() << endl;           // 5
	Heap<int> heap2(heap1);
	cout << heap2.get_top() << endl;           // 4
	heap2.insert(5);
	heap2.make_minimum_tree();
	heap2.insert(9);
	while(!heap2.is_empty())
		cout << heap2.pop_top();               // 1233459
	cout << endl;	
	while(!heap1.is_empty())
		cout << heap1.pop_top();               // 43321
	cout << endl;

	return 0;
}