#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>

class Graph
{
	int size;
	int** data;
public:
	Graph();
	Graph(const Graph& old);
	Graph& operator =(const Graph& old);
	~Graph();

	void alloc();
	void alloc(int size);
	void erase();

	friend std::ostream& operator<<(std::ostream& out, const Graph& put);
	friend std::istream& operator>>(std::istream& in, Graph& put);
};


#endif