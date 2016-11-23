#ifndef _HUFFMAN_TREE_H_INCLUDED_
#define _HUFFMAN_TREE_H_INCLUDED_

#include "binary_tree.h"
#include "heap.h"
#include <iostream>

using namespace std;


template <typename Type>
class HuffmanTree : public BinaryTree<Type>
{
private:
	int weight;
public:
	HuffmanTree(int weight_=0, const Type& x=0) : BinaryTree<Type>::BinaryTree(x), weight(weight_) {}
	HuffmanTree(Type* p, int len);
	HuffmanTree(const HuffmanTree<Type>& t);
	HuffmanTree<Type>& operator=(const HuffmanTree<Type>& t);
	virtual ~HuffmanTree() {}
	virtual void extend(const HuffmanTree<Type>&);
	operator int() { return weight; }
};


template <typename Type>
HuffmanTree<Type>::HuffmanTree(Type* p, int len)
{
	HuffmanTree<Type>* trees = new HuffmanTree<Type>[len];
	for(int i=0; i<len; i++)
	{
		trees[i].weight = p[i].weight;
		trees[i].root -> element = p[i];
	}
	Heap< HuffmanTree<Type> > heap(trees, len);
	delete [] trees;
	HuffmanTree<Type> tree = heap.pop_top();
	while(!heap.is_empty())
	{
		HuffmanTree<Type> tree1 = heap.pop_top();
		tree.extend(tree1);
		heap.insert(tree);
		tree = heap.pop_top();
	}
	*this = tree;
}

template <typename Type>
HuffmanTree<Type>::HuffmanTree(const HuffmanTree<Type>& t)
	: BinaryTree<Type>::BinaryTree(t)
{
	weight = t.weight;
}

template <typename Type>
HuffmanTree<Type>& HuffmanTree<Type>::operator=(const HuffmanTree<Type>& t)
{
	BinaryTree<Type>::operator=(t);
	weight = t.weight;
	return *this;
}

template <typename Type>
void HuffmanTree<Type>::extend(const HuffmanTree<Type>& t)
{
	BinaryTree<Type>::extend(t);
	weight = weight + t.weight;
}


#endif