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
	int weight;                                                 // 记录树的权重
	int num;                                                    // 记录元素个数
public:
	HuffmanTree(int weight_=0, const Type& x=0, int num_=1)
		: BinaryTree<Type>::BinaryTree(x), weight(weight_), num(num_) {}
	HuffmanTree(Type* p, int len);                              // 由给定数组构建huffman tree
	HuffmanTree(const HuffmanTree<Type>& t);
	HuffmanTree<Type>& operator=(const HuffmanTree<Type>& t);
	virtual ~HuffmanTree() {}
	virtual void extend(const HuffmanTree<Type>&);              // 继承重写extend方法
	operator int() { return weight; }                           // 为堆比较权重提供类型转换
	void show_code();                                           // 按遍历顺序输出编码
	void show_code(BinTreeNode<Type>*, char*, int );            // 递归函数
};


template <typename Type>
HuffmanTree<Type>::HuffmanTree(Type* p, int len)
{
	HuffmanTree<Type>* trees = new HuffmanTree<Type>[len];      // 初始化原始节点树
	for(int i=0; i<len; i++)
	{
		trees[i].weight = p[i].weight;
		trees[i].root -> element = p[i];
	}
	Heap< HuffmanTree<Type> > heap(trees, len);                 // 建最小堆
	HuffmanTree<Type> tree = heap.pop_top();
	while(!heap.is_empty())
	{
		HuffmanTree<Type> tree1 = heap.pop_top();               // 获取第二小权重树
		tree.extend(tree1);
		heap.insert(tree);
		tree = heap.pop_top();
	}
	*this = tree;
	delete [] trees;
}

template <typename Type>
HuffmanTree<Type>::HuffmanTree(const HuffmanTree<Type>& t)
	: BinaryTree<Type>::BinaryTree(t)
{
	weight = t.weight;
	num = t.num;
}

template <typename Type>
HuffmanTree<Type>& HuffmanTree<Type>::operator=(const HuffmanTree<Type>& t)
{
	BinaryTree<Type>::operator=(t);
	weight = t.weight;
	num = t.num;
	return *this;
}

template <typename Type>
void HuffmanTree<Type>::extend(const HuffmanTree<Type>& t)
{
	BinaryTree<Type>::extend(t);
	weight = weight + t.weight;
	num = num + t.num;
}

template <typename Type>
void HuffmanTree<Type>::show_code()
{
	BinTreeNode<Type>* current_p = BinaryTree<Type>::root;
	if(current_p == NULL)
		return;	
	int code_len = (num+1)/2 + 1;
	int current_len = 0;
	char* current_code = new char[code_len];
	show_code(current_p, current_code, current_len);
	delete [] current_code;
}

template <typename Type>
void HuffmanTree<Type>::show_code(BinTreeNode<Type>* current_p, char* current_code, int current_len)
{
	if(current_p -> left_child == NULL and current_p -> right_child == NULL)
	{
		current_code[current_len] = '\0';
		cout << current_code << endl;
	}
	if(current_p -> left_child)
	{
		current_code[current_len] = '0';
		show_code(current_p -> left_child, current_code, current_len + 1);
	}
	if(current_p -> right_child)
	{
		current_code[current_len] = '1';
		show_code(current_p -> right_child, current_code, current_len + 1);
	}
}

#endif