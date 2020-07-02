#include "LinkedListFunctions.h"

#include <iostream>

// O(1)
void insertToEnd(Node*& end, int elem)
{
    Node* newNode = new Node;
    newNode->data = elem;
    newNode->next = nullptr;

    if(end)
    {
        end->next = newNode;
    }

    end = newNode;
}

void initialize(Node*& start, int* arr, int n)
{
    Node* end = nullptr;

    for (int i = 0; i < n; ++i)
    {
        insertToEnd(end, arr[i]);
        if (!start)
        {
            start = end;
        }
    }
}

// O(n)
void print(const Node* start)
{
    const Node* current = start;
    while(current)
    {
        std::cout << current->data << ' ';
        current = current->next;
    }

    std::cout << std::endl;
}

// O(n)
void clear(Node*& start)
{
    Node* current = start;
    while(start)
    {
        start = start->next;
        delete current;

        current = start;
    }
}
