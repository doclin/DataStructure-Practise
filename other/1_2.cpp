#include <iostream>

using namespace std;

int main()
{
	char c = '6';
	const int &rc = c;
	int i = 8;
	const int &ri = i;
	cout << &rc << endl;
	cout << (int *)(&c) << endl; // If we use "cout << &c << endl", we will get "6" the value of c, instead of the address of c.
	cout << &ri << endl;
	cout << &i << endl;
	cout << (&rc == (int *)(&c)) << endl; // It won't be compiled successfully under g++ when use &rc==&c, with the error:
	                                      // error: comparison between distinct pointer types ‘const int*’ and ‘char*’ lacks a cast [-fpermissive]
	cout << (&ri == &i) << endl;

	return 0;
}

/*
output:
0x7ffdae11696c
0x7ffdae116967
0x7ffdae116968
0x7ffdae116968
0
1
answer:
When we use "const int &rc = c;", because the type of c is char instead of int, the compiler will create a 
temptory variable and assign it to rc. So the address of rc won't equal to the address of c. When we assign
i to ri, as the types of them are consistent, they will have the same address.

*/