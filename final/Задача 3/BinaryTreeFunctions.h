#pragma once

struct Node
{
    int data{ 1 };

    Node* left{ nullptr };
    Node* right{ nullptr };

    Node() = default;
    Node(int value, Node* leftNode = nullptr, Node* rightNode = nullptr)
        : data(value), left(leftNode), right(rightNode)
    { }
};

// ������� ����� � �������� ����� � �����������
void createTree(Node*& root);

// ������� �������, ����� ������ ����������� ��������� ����� �� ������ �������� � ���,
// ������� ������� ����� �� ����:
// ������� ����� ��� ����� (����� (���� ��������) (����� ��������))
// (2 () ()) �������� �����, ���������� �� ������ � 2

int findIndexOfClosingBracket(const char* expr, int startIndex, int endIndex);

// ������� �������, ����� ������ ����� �� ������ ������� � ������ ������� � ���, 
// ������� ������� ����� �� ����:
// ������� ����� ��� ����� (����� (���� ��������) (����� ��������))

void createTree(Node*& root, const char* expr, int startIndex, int endIndex);

// ��������� ������� ������� ����� ��
// ������� ����� ��� ����� �� ���� (����� (���� ��������) (����� ��������))

void createTree(Node*& root, const char* expr);

void printInOrder(const Node* node);

void clearTree(Node*& root);
