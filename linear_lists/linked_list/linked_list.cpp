#include <iostream>
#include "linked_list.h"
using namespace std;

int main()
{
	LinkedList<int> llist_1(5);
	cout << "length: " << llist_1.length() << endl; //0
	if(llist_1.append(3))
		cout << "length: " << llist_1.length() << endl; //1 3
	if(llist_1.append(1))
		cout << "length: " << llist_1.length() << endl; //2 31
	if(llist_1.insert(2, 4))
		cout << "length: " << llist_1.length() << endl;
	else
		cout << "error" << endl; //error
	if(llist_1.insert(2, 1))
		cout << "length: " << llist_1.length() << endl; //3 321
	cout << llist_1.get(1) << endl; //2
	cout << llist_1[2] << endl; //1
	LinkedList<int> llist_2 = llist_1;
	if(llist_2.append(4))
		cout << "length: " << llist_2.length() << endl; //4 3214


	int i =4;
	if(llist_2.is_in(4))
		cout << "index: " << llist_2.index(4) << endl; //3
	cout << "index: " << llist_1.index(4) << endl; //-1
	if(llist_1.remove(0))
		cout << "length: " << llist_1.length() << endl; //2 21
	if(llist_2.append(5))
		cout << "length: " << llist_2.length() << endl; //5 32145
	cout << llist_2.is_full() << endl;
	if(llist_2.clear())
		cout << llist_2.is_empty() << endl;

	return 0;
}