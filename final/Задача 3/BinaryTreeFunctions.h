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

// създава дърво в диалогов режим с потребителя
void createTree(Node*& root);

// помощна функция, която намира съответната затваряща скоба на дадена отваряща в низ,
// описващ двоично дърво от вида:
// валиден израз със скоби (корен (ляво поддърво) (дясно поддърво))
// (2 () ()) кореново дърво, стойността на корена е 2

int findIndexOfClosingBracket(const char* expr, int startIndex, int endIndex);

// помощна фунцкия, която генера дърво по дадена начална и крайна позиция в низ, 
// описващ двоично дърво от вида:
// валиден израз със скоби (корен (ляво поддърво) (дясно поддърво))

void createTree(Node*& root, const char* expr, int startIndex, int endIndex);

// функцията създава двоично дърво от
// валиден израз със скоби от вида (корен (ляво поддърво) (дясно поддърво))

void createTree(Node*& root, const char* expr);

void printInOrder(const Node* node);

void clearTree(Node*& root);
