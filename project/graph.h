#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include "tree.h"

class Graph
{
	int size;
	int* data;
	int** adjacency;

	void alloc();
	void alloc_data();
	void alloc_adj();
	void erase();
	void erase_data();
	void erase_adj();
public:
	Graph();
	Graph(const Graph& old);
	Graph& operator =(const Graph& old);
	~Graph();

	bool are_neigbours(const int i, const int j) const;

	friend std::ostream& operator<<(std::ostream& out, const Graph& put);
	friend std::istream& operator>>(std::istream& in, Graph& put);

	friend Tree dijkstra(const Graph& graph, int start);
};


#endif