#include "list.h"

Node* sorted_difference(Node* head, Node* rem)
{
	if(head == nullptr) return nullptr;

	Node* result = new Node{head->data, nullptr};
	Node* start = result;

	while(head->next != nullptr)
	{
		
		if(head->data == head->next->data)
			head = head->next;
		else
		{
			head = head->next;

			Node* temp = new Node{head->data, nullptr};
			start->next = temp;

			start = start->next;
		}
	}

	while(result != nullptr && rem != nullptr)
	{
		if(result->data == rem->data)
		{
			Node* temp = result->next;
			delete result;
			result = temp;
			rem = rem->next;
		}
		else if(rem->data < result->data)
			rem = rem->next;
		else
			break;
	}

	start = result;

	while(start->next != nullptr && rem != nullptr)
	{
		if(start->next->data == rem->data)
		{	
			Node* temp = start->next->next;
			delete start->next;
			start->next = temp;
			rem = rem->next;
			start = start->next;
		}
		else if(start->next->data > rem->data)
		{ 
			rem = rem->next;
		}
		else
		{ 
			start = start->next;
		}
	}

	return result;
}