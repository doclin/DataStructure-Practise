#ifndef _GRAPH_UTILS_H_INCLUDED_
#define _GRAPH_UTILS_H_INCLUDED_
#include <iostream>
#include "graph.h"

template <typename Type> void dfs(const Graph<Type>&);
void dfs(double** matrix, bool* records, int num, int ver);
template <typename Type> void bfs(const Graph<Type>&);



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
}

void dfs(double** matrix, bool* records, int num, int ver)
{
	cout << ver << endl;
	records[ver] = true;
	for(int i=0; i<num; i++)
	{
		if(matrix[i]!=0 and records[i]==false)
			dfs(matrix, records, num, i);
	}
}


template <typename Type>
void bfs(const Graph<Type>& g)
{
	int num = g.num_of_vertices();
	bool* records = new bool[num];
	for(int i=0; i<num; i++)
		records[i] = 0;
	double** matrix = g.edge_matrix;	
}




#endif