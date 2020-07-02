#include <cstddef>
#include "LinkedListFunctions.h"

using namespace std;

void remove_singles(Node*&);

int main()
{
    Node* start = nullptr;

    int arr[] = { 1, 2, 2, 3, 4, 4, 5 };
    size_t countElements = sizeof(arr) / sizeof(int);

    initialize(start, arr, countElements);

    print(start);

    remove_singles(start);

    print(start);

    clear(start);

    return 0;
}

void remove_singles(Node*& start)
{
	Node* new_head = nullptr;
	Node* head = start;
	while(head->next != nullptr)
	{
		if(head->data == head->next->data)
		{
			if(new_head == nullptr)
				new_head = head;
			else
				new_head->next = head;
			head = head->next;
		}
		else
		{
			
		}
		head = head->next;
	}
	start = new_head;
}
