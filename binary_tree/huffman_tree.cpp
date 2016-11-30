#include "huffman_tree.h"
#include <iostream>

using namespace std;

struct character
{
	int weight;
	char ch;
	//operator int() { return weight; }
	operator char() { return ch; }
	character(int w=0, char c=0) : weight(w), ch(c) {}
};

int main()
{
	character c[5] = {character(1, 'a'), character(3, 'b'), character(6, 'c'), character(2, 'd'), character(4, 'e')};
	//int a[5] = {1, 3, 6, 2, 4};
	HuffmanTree<character> htree(c, 5);
	cout << htree << endl;
	htree.show_code();
	//htree.pre_order();             //  c e b ad
	//htree.in_order();              // c e b a d

}


/*
		.
	  6    .
	     4   .
	       3   .
	          1  2
*/