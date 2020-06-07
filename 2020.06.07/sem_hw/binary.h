#ifndef BINARY_H_INCLUDED
#define BINARY_H_INCLUDED

#include <iostream>
#include <algorithm>

struct Node
{
	char data;
	Node* left;
	Node* right;
};

Node* new_node(char data)
{
    Node* newnode= new Node;
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;

    return newnode;
}

bool is_operator(char data)
{
	return data == '+' || data == '-' || data == '*' || data == '/';
}

bool has_both(Node* head)
{
	return head->left != nullptr && head->right != nullptr;
}

void push(Node*& head, char data)
{
	if(head == nullptr)
	    head = new_node(data);
	else if(is_operator(data))
	{
		if(head->right != nullptr && !is_operator(head->right->data))
			push(head->left, data);
		else
			push(head->right, data);
	}
	else
	{ 
		Node* oper = nullptr;
		if(head->right != nullptr && is_operator(head->right->data))
			oper = head->right;
		else if(head->left != nullptr && is_operator(head->left->data))
			oper = head->left;

		if(oper != nullptr && ((oper->left == nullptr || (is_operator(oper->left->data) && !has_both(oper->left))) || (oper->right == nullptr || (is_operator(oper->right->data) && !has_both(oper->right)))))
			push(oper, data);
		else if(head->right == nullptr)
			push(head->right, data);
		else
			push(head->left, data);		
	}
}
 
//from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void print(const Node *root, int space)  
{  
    if(root == nullptr)  
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

double calculate(double left, char sign, double right)
{
	switch(sign)
	{
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			return left / right;
		default:
			return left;
	}
}

Node* create_expression_tree(const char* rpn);
double evaluate_expression(const Node* head);


#endif