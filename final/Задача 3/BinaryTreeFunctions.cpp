#include "BinaryTreeFunctions.h"

#include <iostream>
#include <stack>
#include <cstring>

void createTree(Node*& root)
{
    std::cout << "Do you want to create a tree? y(yes) or n(no)...\n";
    char response;
    std::cin >> response;

    if (response == 'y' || response == 'Y')
    {
        int data;
        std::cout << "root: "; std::cin >> data;

        Node* left = nullptr;
        Node* right = nullptr;

        std::cout << "LEFT for root " << data << std::endl;
        createTree(left);

        std::cout << "RIGHT for root " << data << std::endl;
        createTree(right);

        // root = new Node(data, left, right);

        root = new Node;
        root->data = data;
        root->left = left;
        root->right = right;
    }
}

// валиден израз със скоби (корен (ляво поддърво) (дясно поддърво))
// (2 () ()) кореново дърво, стойността на корена е 2
int findIndexOfClosingBracket(const char* expr, int startIndex, int endIndex)
{
    if (startIndex < 0 || endIndex < 0 || startIndex > endIndex)
        return -1;

    std::stack<char> openingBrackets;
    for (int currentIndex = startIndex; currentIndex <= endIndex; ++currentIndex)
    {
        if (expr[currentIndex] == '(')
        {
            openingBrackets.push(expr[currentIndex]);
        }
        else
        {
            if (expr[currentIndex] == ')')
            {
                openingBrackets.pop();

                if (openingBrackets.empty())
                    return currentIndex;
            }
        }
    }

    return -1;
}

void createTree(Node*& root, const char* expr, int startIndex, int endIndex)
{
    if (startIndex < 0 || endIndex < 0 || startIndex > endIndex)
    {
        root = nullptr;
        return;
    }

    int currentIndex = startIndex;

    if (expr[currentIndex] == '(')
    {
        // прескачаме скобата
        ++currentIndex;

        if (isdigit(expr[currentIndex]))
        {
            // започваме да генерираме стойността на корена
            int value = 0;
            while (currentIndex < endIndex && isdigit(expr[currentIndex]))
            {
                value = value * 10 + expr[currentIndex] - '0';
                ++currentIndex;
            }

            // space
            ++currentIndex;

            root = new Node;
            root->data = value;

            int indexClosingBracket = findIndexOfClosingBracket(expr, currentIndex, endIndex);
            if (indexClosingBracket != -1)
            {
                createTree(root->left, expr, currentIndex, indexClosingBracket);
            
                // indexClosingBracket е ), след нея следва интервал и след това е (
                // за да не разглеждаме последната затваряща скоба
                createTree(root->right, expr, indexClosingBracket + 2, endIndex - 1);
            }
        }
        else if (*expr == ')')
        {
            // празно дърво
            root = nullptr;
        }
    }
}

// функцията създава двоично дърво от
// валиден израз със скоби във вида (корен (ляво поддърво) (дясно поддърво))
void createTree(Node*& root, const char* expr)
{
    createTree(root, expr, 0, strlen(expr) - 1);
}

void printInOrder(const Node* node)
{
    // in-order
    if (node)
    {
        printInOrder(node->left);
        std::cout << node->data << ' ';
        printInOrder(node->right);
    }
}

void clearTree(Node*& root)
{
    if (root)
    {
        clearTree(root->left);
        clearTree(root->right);

        delete root;
        root = nullptr;
    }
}