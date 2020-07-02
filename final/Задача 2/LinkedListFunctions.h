#pragma once

struct Node
{
    int data { 0 };
    Node* next { nullptr };

    Node() = default;
};

// ������� �� �������� �� ������� ���� end
void insertToEnd(Node*& end, int elem);

// ������� �� ��������� �� ������ �� ����� �� ���� �����
void initialize(Node*& start, int* arr, int n);

void print(const Node* start);

void clear(Node*& start);
