#include "graph_utils.h"
#include <iostream>

Graph<int> get_graph()
{
	Graph<int> graph(6);
	graph.insert_vertice(2);
	graph.insert_vertice(7);
	graph.insert_vertice(3);
	graph.insert_vertice(5);
	graph.insert_edge(0, 3, 3);
	graph.insert_edge(0, 2, 9);
	graph.insert_edge(1, 2, 1);
	graph.insert_edge(2, 3, 2);
	//graph.insert_edge(3, 1, 4);
	graph.insert_edge(3, 2, 5);	
	/*
	2 7 3 5 * *
	-----------
	0 0 9 3 0 0
	0 0 1 0 0 0              2--1 
	0 0 0 2 0 0             /|  
	0 0 5 0 0 0            0 |
	0 0 0 0 0 0             \|
	0 0 0 0 0 0              3
	*/
	return graph;
}

int main()
{
	Graph<int> graph(get_graph());
	dfs(graph); //0231
	bfs(graph); //0231

}