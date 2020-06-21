#include "tree.h"


void free(Node*& root)
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

void remove(Node*& root, Node*& leaf)
{
	if(root != nullptr)
	{
		for(int i = 0; i < root->children.size(); i++)
		{
			if(!root->children[i]->children.empty())
			{
				remove(root->children[i], leaf);
			}
			if(root->children[i]->id == leaf->id)
				root->children.erase(root->children.begin() + i);
		}
	}
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

void print(Node*& put)
{
	if(put != nullptr)
	{
		std::cout << "v" << put->id;

		for(int i = 0; i < put->children.size(); i++)
		{
			if(put->children[i]->children.empty())
				std::cout << "v" << put->children[i]->id;
			else
				print(put->children[i]);
			std::cout << "|";
		}
	}
}

void data_print(Node*& put)
{
	if(put != nullptr)
	{
		std::cout << " v" << put->id << ": " << std::endl 
		          << "   data - " << put->data << std::endl 
		          << "   path to root - " << put->path_weight << std::endl;

		for(int i = 0; i < put->children.size(); i++)
		{
			if(put->children[i]->children.empty())
				std::cout << " v" << put->children[i]->id << ": " << std::endl 
		          << "   data - " << put->children[i]->data << std::endl 
		          << "   path to root - " << put->children[i]->path_weight << std::endl;
			else
				data_print(put->children[i]);
		}
	}
}

