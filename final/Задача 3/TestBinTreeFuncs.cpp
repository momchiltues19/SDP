#include "BinaryTreeFunctions.h"

int main()
{
    Node* root = nullptr;

    //              1
    //      2               3
    //  4       5       6   
    createTree(root, "(1 (2 (4 () ()) (5 () ())) (3 (6 () ()) ()))");
    printInOrder(root);
    clearTree(root);

    return 0;
}