#include "graph.h"

Graph::Graph()
{
	size = 0;
	alloc();
}

Graph::Graph(const Graph& old)
{
	size = old.size;
	alloc();
	for(int i = 0; i < size; i++)
	{
		data[i] = old.data[i];
		for(int j = 0; j < size; j++)
		{
			adjacency[i][j] = old.adjacency[i][j];
		}
	}
}

Graph&  Graph::operator =(const Graph& old)
{
	erase();
	*this = Graph(old);
	return *this;
}

Graph::~Graph()
{
	erase();
}

void Graph::alloc()
{
	alloc_data();
	alloc_adj();
}

void Graph::erase()
{
	erase_data();
	erase_adj();
}

void Graph::alloc_data()
{
	data = new int[size];
}

void Graph::erase_data()
{
	delete [] data;
}

void Graph::alloc_adj()
{
	adjacency = new int*[size];
	for (int i = 0; i < size; ++i)
	    adjacency[i] = new int[size];
}

void Graph::erase_adj()
{
	for (int i = 0; i < size; ++i)
	    delete [] adjacency[i];
	delete [] adjacency;
}


bool Graph::are_neigbours(const int i, const int j) const
{
	return adjacency[i][j] > 0;
}


std::ostream& operator<<(std::ostream& out, const Graph& put)
{
	out << "Graph has data:" << std::endl;
	for(int i = 0; i < put.size; i++)
	{
		out << put.data[i] << " ";
	}
	out << std::endl;

	out << "Graph has adjacency matrix:" << std::endl;
	for(int i = 0; i < put.size; i++)
	{
		for(int j = 0; j < put.size; j++)
		{
			out << put.adjacency[i][j] << " ";
		}
		out << std::endl;
	}

	return out;
}

std::istream& operator>>(std::istream& in, Graph& put)
{
	put.erase();

	std::cout << "Input array size: ";
	std::cin >> put.size;

	put.alloc_data();

	std::cout << "Input graph data:" << std::endl;
	for(int i = 0; i < put.size; i++)
	{
		in >> put.data[i];
	}

	put.alloc_adj();

	std::cout << "Input graph adjacency matrix:" << std::endl;
	for(int i = 0; i < put.size; i++)
	{
		for(int j = 0; j < put.size; j++)
		{
			in >> put.adjacency[i][j];
		}
	}

	return in;
}

Tree dijkstra(const Graph& graph, int start)
{
	Tree result;
	std::vector<Node*> unvisited;

	for(int i = 0; i < graph.size; i++)
	{
		if(i == start)
			unvisited.push_back(new_node(i,graph.data[i],0));
		else
			unvisited.push_back(new_node(i,graph.data[i],-1));

	}

	while(!unvisited.empty())
	{
		Node* curr = min_weight(unvisited);
		int curr_pos = 0, i = curr->id;
		for(int j = 0; j < unvisited.size(); j++)
		{
			int id = unvisited[j]->id;
			if(id == i)
			{
				curr_pos = j;
			}
			if(graph.are_neigbours(i, id))
			{
				int distance = curr->path_weight + graph.adjacency[i][id];
				if(unvisited[id]->path_weight == -1 || distance < unvisited[id]->path_weight)
				{
					unvisited[id]->path_weight = distance;
					result.remove(unvisited[id]);
					curr->children.push_back(unvisited[id]);
				}
			}
		}
		unvisited.erase(unvisited.begin() + curr_pos);
		result.push(curr);
	}

	return result;
}