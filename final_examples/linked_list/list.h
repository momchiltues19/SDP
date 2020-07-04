#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct Node
{
	int data;
	Node* next;
};

void push(Node*& head, int x);
void print(Node* head);

int get_nth(Node* head, int index);
void insert_nth(Node*& head, int index, int x);
void delete_list(Node*& head);
Node* copy_list(Node* head);


#endif