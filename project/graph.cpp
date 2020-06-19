#include "graph.h"

Graph::Graph()
{
	size = 0;
	alloc();
}

Graph::Graph(const Graph& old)
{
	size = old.size;
	erase();
	alloc();
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			data[i][j] = old.data[i][j];
		}
	}
}

Graph&  Graph::operator =(const Graph& old)
{
	return *this = Graph(old);
}

Graph::~Graph()
{
	erase();
}


void Graph::alloc()
{
	alloc(size);
}

void Graph::alloc(int size)
{
	data = new int*[size];
	for (int i = 0; i < size; ++i)
	    data[i] = new int[size];
}

void Graph::erase()
{
	for (int i = 0; i < size; ++i)
	    delete [] data[i];
	delete [] data;
}


std::ostream& operator<<(std::ostream& out, const Graph& put)
{
	out << "Graph is:" << std::endl;
	for(int i = 0; i < put.size; i++)
	{
		for(int j = 0; j < put.size; j++)
		{
			out << put.data[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Graph& put)
{
	std::cout << "Input array size: ";
	std::cin >> put.size;

	put.alloc();

	for(int i = 0; i < put.size; i++)
	{
		for(int j = 0; j < put.size; j++)
		{
			in >> put.data[i][j];
		}
	}

	return in;
}