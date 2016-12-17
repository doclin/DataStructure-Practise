#ifndef _GRAPH_H_INCLUDED_
#define _GRAPH_H_INCLUDED_
#include "../linear_lists/sequential_list/sequential_list.h"
#include <iostream>

template <typename Type> class Graph;

template <typename Type> void dfs(const Graph<Type>&);
template <typename Type> void bfs(const Graph<Type>&);


template <typename Type>
class Graph
{
private:
	SequentialList<Type> ver_list;
	double** edge_matrix;
	int max_size;
public:
	Graph(int max_size_=19);
	Graph(const Graph& g);
	Graph& operator=(const Graph& g);
	~Graph();
	bool insert_vertice(const Type& v);
	bool insert_edge(int u, int v, double weight);
	bool remove_vertice(int i);
	bool remove_edge(int u, int v);
	bool exist(int u, int v) const;
	bool is_full() const;
	bool is_empty() const;
	int num_of_vertices() const;
	int num_of_edges() const;
	Type get_vertice(int i) const;
	double get_weight(int u, int v) const;
	void print_matrix() const;
	void clear();
	void clear_edges();
	friend void dfs<Type>(const Graph<Type>&);
	friend void bfs<Type>(const Graph<Type>&);
};


template <typename Type>
Graph<Type>::Graph(int max_size_)
	: max_size(max_size_), ver_list(max_size_)
{
	edge_matrix = new double*[max_size];
	for(int i=0; i<max_size; i++)
	{
		edge_matrix[i] = new double[max_size];
		for(int j=0; j<max_size; j++)
			edge_matrix[i][j] = 0;
	}
}

template <typename Type>
Graph<Type>::Graph(const Graph& g)
{
	max_size = g.max_size;
	ver_list = g.ver_list;
	edge_matrix = new double*[max_size];
	for(int i=0; i<max_size; i++)
	{
		edge_matrix[i] = new double[max_size];
		for(int j=0; j<max_size; j++)
			edge_matrix[i][j] = g.edge_matrix[i][j];
	}
}

template <typename Type>
Graph<Type>& Graph<Type>::operator=(const Graph& g)
{
	max_size = g.max_size;
	ver_list = g.ver_list;
	for(int m=0; m<max_size; m++)
	{
		delete [] edge_matrix[m];
	}
	delete [] edge_matrix;
	edge_matrix = new double*[max_size];
	for(int i=0; i<max_size; i++)
	{
		edge_matrix[i] = new double[max_size];
		for(int j=0; j<max_size; j++)
			edge_matrix[i][j] = g.edge_matrix[i][j];
	}

	return *this;
}

template <typename Type>
Graph<Type>::~Graph()
{
	for(int m=0; m<max_size; m++)
	{
		delete [] edge_matrix[m];
	}
	delete [] edge_matrix;	
}

template <typename Type>
bool Graph<Type>::insert_vertice(const Type& v)
{
	if(is_full())
		return false;
	ver_list.append(v);
	return true;
}

template <typename Type>
bool Graph<Type>::insert_edge(int u, int v, double weight)
{
	if(exist(u, v) or is_full())
		return false;
	if(u >= ver_list.length() or v >= ver_list.length())
		return false;
	edge_matrix[u][v] = weight;
	return true;
}

template <typename Type>
bool Graph<Type>::remove_vertice(int i)
{
	int len = ver_list.length();
	if(i >= len)
		return false;
	delete [] edge_matrix[i];
	for(int j=i; j<len-1; j++)
	{
		edge_matrix[j] = edge_matrix[j+1];
	}
	edge_matrix[len-1] = new double[max_size];
	for(int k=0; k<len; k++)
		edge_matrix[len-1][k] = 0;
	for(int m=0; m<len-1; m++)
	{
		edge_matrix[m][i] = 0;
		for(int n=i+1; n<len; n++)
		{
			if(edge_matrix[m][n] != 0)
				edge_matrix[m][n-1] = edge_matrix[m][n];
		}
		edge_matrix[m][len-1] = 0;
	}
	ver_list.remove(i);
	return true;
}

template <typename Type>
bool Graph<Type>::remove_edge(int u, int v)
{
	if(!exist(u, v))
		return false;
	edge_matrix[u][v] = 0;
	return true;
}

template <typename Type>
bool Graph<Type>::exist(int u, int v) const
{
	if(edge_matrix[u][v] == 0)
		return false;
	return true;
}

template <typename Type>
bool Graph<Type>::is_full() const
{
	return ver_list.is_full();
}

template <typename Type>
bool Graph<Type>::is_empty() const
{
	return ver_list.is_empty();
}

template <typename Type>
int Graph<Type>::num_of_vertices() const
{
	return ver_list.length();
}

template <typename Type>
int Graph<Type>::num_of_edges() const
{
	int len = ver_list.length();
	int num = 0;
	for(int i=0; i<len; i++)
	{
		for(int j=0; j<len; j++)
		{
			if(edge_matrix[i][j] != 0)
				num++;
		}
	}
	return num;
}

template <typename Type>
Type Graph<Type>::get_vertice(int i) const
{
	return ver_list[i];
}

template <typename Type>
double Graph<Type>::get_weight(int u, int v) const
{
	return edge_matrix[u][v];
}

template <typename Type>
void Graph<Type>::print_matrix() const
{
	for(int i=0; i<max_size; i++)
	{
		for(int j=0; j<max_size; j++)
		{
			cout << edge_matrix[i][j] <<" ";
		}
		cout << endl;
	}
}

template <typename Type>
void Graph<Type>::clear()
{
	clear_edges();
	ver_list.clear();
}

template <typename Type>
void Graph<Type>::clear_edges()
{
	for(int i=0; i<max_size; i++)
	{
		for(int j=0; j<max_size; j++)
		{
			edge_matrix[i][j] = 0;
		}
	}
}

#endif
