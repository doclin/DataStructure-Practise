#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	Stack<int> s1;
	int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for(int i=0; i<9; i++)
	{
		s1.push(a[i]);
		cout << "push " << a[i] << " in s1" << endl;
	}
	cout << "pop " << s1.pop() << " from s1" << endl;
	cout << "--------------------------------" << endl;
	Stack<int> s2(s1);
	for(int j=0; j<8; j++)
	{
		cout << "pop " << s2.pop() << " from s2" << endl;
	}
	cout << s2.is_empty() << endl;
	s2 = s1;
	cout << "pop " << s2.pop() << " from s2" << endl;
	cout << "--------------------------------" << endl;
	s1.clear();
	cout << s1.is_empty() << endl;

	return 0;
}