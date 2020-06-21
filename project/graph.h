#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include "tree.h"

class Graph
{
	int size;
	int* data;
	int** adjacency;

	void alloc(); //combination of the two below
	void alloc_data(); //allocate data array
	void alloc_adj(); //allocate adjacency matrix
	void erase(); //combination of the two below
	void erase_data(); //deallocate data array 
	void erase_adj(); //deallocate adjacency matrix
public:
	Graph();
	Graph(const Graph& old);
	Graph& operator =(const Graph& old);
	~Graph();

	bool are_neighbours(const int i, const int j) const; //checks if vertices with given ids are neighbours

	friend std::ostream& operator<<(std::ostream& out, const Graph& put); 
	friend std::istream& operator>>(std::istream& in, Graph& put);

	friend Node* dijkstra(const Graph& graph, int start); //the task at hand
};


#endif