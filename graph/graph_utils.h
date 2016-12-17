#ifndef _GRAPH_UTILS_H_INCLUDED_
#define _GRAPH_UTILS_H_INCLUDED_
#include <iostream>
#include "graph.h"
#include "../queue/queue.h"

template <typename Type> void dfs(const Graph<Type>&);
void dfs(double** matrix, bool* records, int num, int ver);
template <typename Type> void bfs(const Graph<Type>&);
void bfs(double** matrix, bool* records, int num, int ver, Queue<int>& queue);
//template <typename Type> Graph<Type> prim_minimum_tree(const Graph<Type>&);
//template <typename Type> Graph<Type> kruskal_minimum_tree(const Graph<Type>&);


//deep first search
template <typename Type>
void dfs(const Graph<Type>& g)
{
	int num = g.num_of_vertices();
	bool* records = new bool[num];
	for(int i=0; i<num; i++)
		records[i] = 0;
	double** matrix = g.edge_matrix;
	while(true)
	{
		int i = 0;
		while(i<num)
		{
			if(records[i] == false)
			{
				dfs(matrix, records, num, i);
				break;
			}
			i++;
		}
		if(i == num)
			break;
	}
	delete [] records;
}

void dfs(double** matrix, bool* records, int num, int ver)
{
	cout << ver << endl;
	records[ver] = true;
	for(int i=0; i<num; i++)
	{
		if(matrix[ver][i]!=0 and records[i]==false)
			dfs(matrix, records, num, i);
	}
}


//bread first search
template <typename Type>
void bfs(const Graph<Type>& g)
{
	int num = g.num_of_vertices();
	bool* records = new bool[num];
	for(int i=0; i<num; i++)
		records[i] = 0;
	double** matrix = g.edge_matrix;
	Queue<int> queue;

	cout << 0 << endl;
	records[0] = true;
	queue.enqueue(0);
	while(true)
	{
		while(!queue.is_empty())
		{
			int ver = queue.dequeue();
			bfs(matrix, records, num, ver, queue);
		}
		int j = 0;
		while(j<num)
		{
			if(records[j] == false)
			{
				cout << j << endl;
				records[j] = true;
				queue.enqueue(j);
				break;
			}
			j++;
		}
		if(j == num)
			break;
	}
	delete [] records;
}

void bfs(double** matrix, bool* records, int num, int ver, Queue<int>& queue)
{
	for(int i=0; i<num; i++)
	{
		if(matrix[ver][i]!=0 and records[i]==false)
		{
			cout << i << endl;
			records[i] = true;
			queue.enqueue(i);
		}
	}
}

#endif