#include "list.h"

#include <iostream>

int get_nth(Node* head, int index)
{
	if(head == nullptr || index < 0)
	{
		std::cout << "Invalid input" << std::endl;
		return -1;
	}
	for(int i = 0; i < index; i++)
	{
		head = head->next;
		if(head == nullptr)
		{
			std::cout << "Index is too big" << std::endl;
			return -1;
		}
	}
	return head->data;
}

void insert_nth(Node*& head, int index, int x)
{
	Node* temp = new Node;
	temp->data = x;
	if(head == nullptr || index == 0)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		Node* start = head;
		for(int i = 1; i < index; i++)
		{
			start = start->next;
			if(start->next == nullptr) break;
		}
		temp->next = start->next;
		start->next = temp;
	}
}

void delete_list(Node*& head)
{
	while(head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	head == nullptr;
}

Node* copy_list(Node* head)
{
	Node* new_head = nullptr;
	Node* result = new_head;
	while(head != nullptr)
	{
		if(new_head == nullptr)
		{
			new_head->data = head->data;
			new_head->next = nullptr;
		}
		else
		{
			Node* temp = new Node;
			temp->data = head->data;
			temp->next = nullptr;
			new_head->next = temp;
		}
		new_head = new_head->next;
		head = head->next;
	}
	return result;
}