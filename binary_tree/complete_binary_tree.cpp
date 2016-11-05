#include "complete_binary_tree.h"
#include <iostream>

using namespace std;

int main()
{
	char array[8] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	CompleteBinTree<char> tree(array, 8);
	tree.pre_order();        // ABDHECFG
	cout << endl;
	tree.in_order();         // HDBEAFCG
	cout << endl;
	tree.post_order();       // HDEBFGCA

	return 0;
}

/*
            A
         B     C
       D   E  F  G
     H


*/