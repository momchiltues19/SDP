#include "binary.h"

using namespace std;

int main()
{
	Node* root = nullptr;
	for(int i = 1; i <= 7; i++)
		push(root, i);
	print(root, 0);

	cout << count_nodes(root) << endl;

	free(root);

	return 0;
}

int count_nodes(Node* root)
{
	if(root == nullptr)
		return 0;
	else
		return 1 + count_nodes(root->left) + count_nodes(root->right);
}