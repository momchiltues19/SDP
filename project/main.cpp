#include "graph.h"

using namespace std;

int main()
{
	Graph g;
	Node* t;

	cin >> g;

	cout << endl << g << endl;

	t = dijkstra(g, 0);

	cout << "Result tree is: " << endl << " ";
	print(t);
	cout << endl << endl;

	cout << "Information in tree: " << endl;
	data_print(t);
	cout << endl;

	free(t);

	return 0;
}