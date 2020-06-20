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

class Tree
{
	Node* root;
public:
	Tree();
	Tree(Node*& root);
	Tree(const Tree& old);
	Tree& operator=(const Tree& old);
	~Tree();

	void free(Node*& root);
	void push(Node*& leaf);
	void remove(Node*& leaf);

	friend std::ostream& operator<<(std::ostream& out, const Tree& put);
};

Node* new_node(int id, int data, int path_weight);
Node*& min_weight(std::vector<Node*> vertices);

std::ostream& operator<<(std::ostream& out, const Node& put);

#endif