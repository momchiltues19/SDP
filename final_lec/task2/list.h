#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

struct Node
{
	int data;
	Node* next;
};

void push(Node*& head, int x);
void print(Node* head);
void free(Node* head);

Node* sorted_difference(Node* a,Node* b);


#endif