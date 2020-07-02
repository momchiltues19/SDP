#include "graph.h"

using namespace std;

//Project: Dijkstra’s Algorithm
//Made by:
//		Kalin Vurbanov, 11286
//		Momchil Todorov, 11292

int main()
{
	Graph graph;
	Node* tree;
	int num;

	cin >> graph;
	cout << endl << "Input vertex id: ";
	cin >> num;

	tree = dijkstra(graph, num);

	cout << endl << graph << endl;

	cout << "Result tree is: " << endl << " ";
	print(tree);
	cout << endl << endl;

	cout << "Information in tree: " << endl;
	data_print(tree);
	cout << endl;

	free(tree);

	return 0;
}