#ifndef BINARY_H_INCLUDED
#define BINARY_H_INCLUDED

#include <iostream>
#include <algorithm>

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* new_node(int data)
{
    Node* newnode= new Node;
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;

    return newnode;
}

//Returns ammount of FULL layers of the binary tree
int layer_count(Node* head)
{
	int count = 1;

	if(head->left != nullptr && head->right != nullptr)
		count += std::min(layer_count(head->left), layer_count(head->right));

	return count;
}

void push(Node*& head, int data)
{
	if(head == nullptr)
	    head = new_node(data);
	else
	{
	    if(head->left == nullptr)
	    	push(head->left, data);
	    else if(head->right == nullptr)
	    	push(head->right, data);
	    else
	    {
	    	if(layer_count(head->left)>layer_count(head->right))
	    		push(head->right, data);
	    	else
	    		push(head->left, data);
	    }
	}

}

//from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void print(Node *root, int space)  
{  
    if(root == NULL)  
        return;  
   	space += 9;  
  
    print(root->right, space);  
 	std::cout << std::endl; 

    for (int i = 9; i < space; i++)  
        std::cout << " ";  

    std::cout << root->data << "\n";  
   	print(root->left, space);  
}  


void free(Node*& head)
{
	if(head != nullptr)
	{
		free(head->left);
		free(head->right);

		delete head;
	}
}

int count_nodes(Node* root);


#endif