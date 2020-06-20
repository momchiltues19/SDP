#include "tree.h"

Tree::Tree()
{
	root = nullptr;
}

Tree::Tree(Node*& root)
{
	this->root = root;
}

Tree::Tree(const Tree& old)
{
	root = old.root;
}

Tree&  Tree::operator=(const Tree& old)
{
	free(root);
	root = old.root;
	return *this;
}

Tree::~Tree()
{
	free(root);
}

void Tree::free(Node*& root)
{
	if(root != nullptr)
	{
		for(int i = 0; i < root->children.size(); i++)
    	{
    		free(root->children[i]);
    	}
    	delete root;
    }
}

void Tree::push(Node*& leaf)
{
	if(root == nullptr)
	{
		root = leaf;
	}
}

void Tree::remove(Node*& leaf)
{
	if(root != nullptr)
	{
		for(int i = 0; i < root->children.size(); i++)
		{
			if(!root->children[i]->children.empty())
			{
				Tree child(root->children[i]);
				child.remove(leaf);
			}
			if(root->children[i]->id == leaf->id)
				root->children.erase(root->children.begin() + i);
		}
	}
}

///TODO - Fix recurision
std::ostream& operator<<(std::ostream& out, const Tree& put)
{
	out << put.root;

	for(int i = 0; i < put.root->children.size(); i++)
	{
		out << put.root->children[i];
		out << "|";
	}
	return out;
}

Node* new_node(int id, int data, int path_weight)
{
    Node* new_node = new Node;

    new_node->id = id;
    new_node->data = data;
    new_node->path_weight = path_weight;

    return new_node;
}

Node*& min_weight(std::vector<Node*> vertices)
{
	int min_id = 0;

	for(int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i]->path_weight != -1)
		{
			if(vertices[min_id]->path_weight == -1 || vertices[i]->path_weight < vertices[min_id]->path_weight)
				min_id = i;
		}		
	}

	return vertices[min_id];
}


std::ostream& operator<<(std::ostream& out, const Node*& put)
{
	out << "---" << put->path_weight << "---" << "v" << put->id << ": " << put->data << std::endl;
	
	return out;
}