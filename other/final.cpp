/*
Write a function to produce huffman codes for a set of weights.

The following demands must be satisfied:

(1) The function prototype should be like this:   void HuffmanCode(double weights[], int size);

(2) Inside the function, a variable like char **hcodes should be declared, 
	and the space for huffman codes must be allocated dynamically using new[] operation;

(3)When building huffman tree, a minimum heap must be created by repeating the adjustDown() operation;

(4) After outputting all the huffman codes, the dynamically allocated space must be released;
*/

#include <iostream>
#include "../binary_tree/heap.h"

using namespace std;

static int num = 0;                                        // Result's num record

void HuffmanCode(double weights[], int size);
class HNode                                                // Huffman Tree's node
{
public:
	double weight;
	HNode* left_child;
	HNode* right_child;
	HNode(double w=0, HNode* pl=NULL, HNode* pr=NULL)
		: weight(w), left_child(pl), right_child(pr) {}
	operator double() { return weight; }                   // To be compared by heap
};
void get_code(HNode*, char*, int, char**);
void show_code(char**, int);


int main()
{
	double a[6] = {9, 11, 13, 3, 5, 12};
	HuffmanCode(a, 6);

	return 0;
}



void HuffmanCode(double weights[], int size)
{
	/* build a huffman tree */
	HNode* nodes = new HNode[size];
	for (int i=0; i<size; i++)
	{
		nodes[i].weight = weights[i];                      // Init array to build mini heap
	}
	Heap<HNode> heap(nodes, size);
	HNode* node = new HNode(heap.pop_top());
	while(!heap.is_empty())
	{
		HNode* node1 = new HNode(heap.pop_top());
		HNode new_node(node->weight + node1->weight, node, node1);
		heap.insert(new_node);
		node = new HNode(heap.pop_top());
	}
	/* output the huffmantree */
	int code_max_len = size;                     // Huffman code's max length
	int code_current_len = 0;
	char** hcodes = new char*[size];                       // Result set
	for(int i=0; i<size; i++)
		hcodes[i] = new char[code_max_len];
	char current_code[code_max_len];                       // Current code in traverse
	get_code(node, current_code, code_current_len, hcodes);// Traverse the Huffman tree and store all codes in result set
	show_code(hcodes, size);
	delete [] nodes;
	for(int j=0; j<size; j++)
		delete [] hcodes[j];
	delete [] hcodes;
}

void get_code(HNode* p, char* current_code, int code_current_len, char** result)
{
	if(p -> left_child == NULL and p -> right_child == NULL)
	{
		current_code[code_current_len] = '\0';
		for(int i=0; i<=code_current_len; i++)
		{
			result[num][i] = current_code[i];
		}
		num++;
	}
	if(p -> left_child)
	{
		current_code[code_current_len] = '0';
		get_code(p -> left_child, current_code, code_current_len + 1, result);
	}
	if(p -> right_child)
	{
		current_code[code_current_len] = '1';
		get_code(p -> right_child, current_code, code_current_len + 1, result);
	}
	delete p;
}

void show_code(char** result, int size)
{
	for(int i=0; i<size; i++)
	{
		cout << result[i] << endl;
	}
}