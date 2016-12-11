#include "graph.h"
#include <iostream>

using namespace std;

int main()
{
	Graph<int> graph(6);
	/*
	* * * * * *
	-----------
	0 0 0 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 0
	*/
	cout << graph.is_empty() << endl;             // 1
	cout << graph.num_of_vertices() << endl;      // 0
	cout << graph.num_of_edges() << endl;         // 0
	graph.insert_vertice(2);
	graph.insert_vertice(7);
	graph.insert_vertice(3);
	graph.insert_vertice(5);
	graph.insert_edge(0, 1, 3);
	graph.insert_edge(0, 2, 9);
	graph.insert_edge(1, 2, 1);
	graph.insert_edge(2, 3, 2);
	graph.insert_edge(3, 0, 4);
	graph.insert_edge(3, 2, 5);
	/*
	2 7 3 5 * *
	-----------
	0 3 9 0 0 0
	0 0 1 0 0 0
	0 0 0 2 0 0
	4 0 5 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 0
	*/
	cout << graph.num_of_vertices() << endl;       // 4
	cout << graph.num_of_edges() << endl;	       // 6
	cout << graph.get_vertice(2) << endl;          // 3
	cout << graph.get_weight(2, 3) << endl;        // 2
	graph.remove_edge(3, 0);
	graph.remove_vertice(1);
	/*
	2 3 5 * * *
	-----------
	0 9 0 0 0 0
	0 0 2 0 0 0
	0 5 0 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 0
	0 0 0 0 0 0
	*/
	cout << graph.num_of_vertices() << endl;       // 3
	cout << graph.num_of_edges() << endl;	       // 3
	cout << graph.get_vertice(2) << endl;          // 5
	cout << graph.get_weight(2, 1) << endl;        // 5
	cout << graph.exist(2, 0) << endl;             // 0
	cout << graph.is_full() << endl;               // 0
	Graph<int> graph1(graph);
	graph1 = graph;
	cout << graph1.get_weight(0, 1) << endl;       // 9


	return 0;
}