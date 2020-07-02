#pragma once

struct Node
{
    int data { 0 };
    Node* next { nullptr };

    Node() = default;
};

// функция за добавяне на елемент след end
void insertToEnd(Node*& end, int elem);

// функция за създаване на списък по масив от цели числа
void initialize(Node*& start, int* arr, int n);

void print(const Node* start);

void clear(Node*& start);
