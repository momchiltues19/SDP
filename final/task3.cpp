#include "BinaryTreeFunctions.h"

using namespace std;

bool are_prime_at(const Node* , int);
bool is_prime(int);

int main()
{
    Node* root = nullptr;

    //              1
    //      2               3
    //  4       5       6   
    createTree(root, "(1 (2 (4 () ()) (5 () ())) (3 (6 () ()) ()))");
    printInOrder(root);
    cout << boolalpha;
    cout << are_prime_at(2) << endl;
    cout << are_prime_at(1) << endl;
    clearTree(root);

    return 0;
}

bool are_prime_at(const Node* root, int k)
{
	if(root == nullptr)
		return true;
	else if(k == 0)
		return is_prime(root->data);
	else
		return are_prime_at(root->left, k-1) && are_prime_at(root->right, k-1);
}

bool is_prime(int a)
{
	for(int i = 2; i <= a/2; ++i)
	{
		if(a % i == 0)
		{
			return false;
		}
	}
	return true;
}

