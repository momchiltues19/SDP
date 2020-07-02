#include "LinkedListFunctions.h"

int main()
{
    Node* start = nullptr;

    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    size_t countElements = sizeof(arr) / sizeof(int);

    initialize(start, arr, countElements);
    print(start);
    clear(start);

    return 0;
}