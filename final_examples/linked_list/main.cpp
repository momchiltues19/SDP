#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	Node* head = nullptr;
	Node* empty = nullptr;

	for(int i = 0; i < 10; i++)
	{
		push(head, i);
	}
	print(head);

	empty = copy_list(head);

	print(empty);

	insert_nth(head, 2, -3);

	print(head);
	print(empty);

	delete_list(head);
	//delete_list(empty);

	return 0;
}

void push(Node*& head, int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = nullptr;
	if(head == nullptr)
		head = temp;
	else
	{
		Node* temp1 = head;
		while(temp1->next != nullptr)
			temp1 = temp1->next;
		temp1->next = temp;
	}
}

void print(Node* head)
{
	cout << "List: ";
	while(head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	std::cout << std::endl;
}
