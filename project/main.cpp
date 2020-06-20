#include "graph.h"

using namespace std;

int main()
{
	Graph g;
	Tree t;

	cin >> g;

	cout << g;

	t = dijkstra(g, 1);

	cout << t;

	return 0;
}