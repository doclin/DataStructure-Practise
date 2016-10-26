#include <iostream>
#include "sequential_list.h"
using namespace std;

int main()
{
	SequentialList<int> slist_1(5);
	cout << "length: " << slist_1.length() << endl; //0
	if(slist_1.append(3))
		cout << "length: " << slist_1.length() << endl; //1 3
	if(slist_1.append(1))
		cout << "length: " << slist_1.length() << endl; //2 31
	if(slist_1.insert(2, 4))
		cout << "length: " << slist_1.length() << endl;
	else
		cout << "error" << endl; //error
	if(slist_1.insert(2, 1))
		cout << "length: " << slist_1.length() << endl; //3 321
	cout << slist_1.get(1) << endl; //2
	cout << slist_1[2] << endl; //1
	SequentialList<int> slist_2 = slist_1;
	if(slist_2.append(4))
		cout << "length: " << slist_2.length() << endl; //4 3214


	int i =4;
	if(slist_2.is_in(4))
		cout << "index: " << slist_2.index(4) << endl; //3
	cout << "index: " << slist_1.index(4) << endl; //-1
	if(slist_1.remove(0))
		cout << "length: " << slist_1.length() << endl; //2 21
	if(slist_2.append(5))
		cout << "length: " << slist_2.length() << endl; //5 32145
	cout << slist_2.is_full() << endl;
	if(slist_2.clear())
		cout << slist_2.is_empty() << endl;

	return 0;
}