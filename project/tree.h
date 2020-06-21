#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include <vector>

struct Node
{ 
	int id;
	int data;
	int path_weight;
	std::vector<Node*> children;
}; 

void free(Node*& root); //dealloc
Node* new_node(int id, int data, int path_weight);
Node*& min_weight(std::vector<Node*> vertices); //finds and returns Node with minimum path_weight
void remove(Node*& root, Node*& leaf); //removes all instances of given Node from tree

void print(Node*& put); //prints structural view of tree
void data_print(Node*& put); //prints information of each node in tree

#endif