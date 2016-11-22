#include "huffman_tree.h"
#include <iostream>

using namespace std;

int main()
{
	int a[5] = {1, 3, 6, 2, 4};
	HuffmanTree<int> htree(a, 5);
	cout << (int)htree << endl;
	htree.pre_order();             // 060403012
	htree.in_order();              // 604030102

}


/*
		.
	  6    .
	     4   .
	       3   .
	          1  2
*/