#include "list.h"

using namespace std;

int main()
{
	Node* head = nullptr;
	Node* empty = nullptr;

	push(head,1);
	push(head,1);
	push(head,2);
	push(head,2);
	push(head,2);
	push(head,4);
	push(head,6);
	push(head,8);
	push(head,9);

	push(empty,1);
	push(empty,2);
	push(empty,3);
	push(empty,8);
	push(empty,8);

	print(head);
	print(empty);

	Node* result = sorted_difference(head, empty);

	print(result);

	free(head);
	free(empty);
	free(result);

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

void free(Node* head)
{
	while(head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	head == nullptr;
}
