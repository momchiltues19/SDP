#include "binary.h"

using namespace std;

int main()
{
	int n;

	//TASK 1//
	cout << "Array size?: ";
	cin >> n;

	int* arr = new int[n];

	cout << "Array elements: " << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	Node* head = to_binary_tree(arr, n);

	cout << "Resulting tree: " << endl;
	print(head, 0);

	free(head);

	delete [] arr;
	//END//

	//TASK 2//
	cout << "Input number: ";
	cin >> n;

	cout << "Number of diffrent BSTs is " << calc_trees(n) << endl; 

	//END//

	return 0;
}

Node* to_binary_tree(int* arr, int n)
{
	Node* head = nullptr;
	for(int i = 0; i < n; i++)
		push(head, arr[i]);
	return head;
}

//(2n)! / ((n + 1)! * n!) 
unsigned long int calc_trees(int n)
{
	return factorial(2*n)/(factorial(n+1)*factorial(n));
}

