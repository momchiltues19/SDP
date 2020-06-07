#include "binary.h"
#include <string.h>

#define STRING_SIZE 100

using namespace std;

int main()
{

	Node* head = nullptr;

	//TASK 1//
	char* string = new char [STRING_SIZE+1];

	cout << "Input rpn expression: ";
	cin >> string;
	head = create_expression_tree(string);

	print(head, 0);
	//END//

	//TASK 2// 
	cout << "Result is: " << evaluate_expression(head) << endl;
	//END//

	free(head);

	return 0;
}

Node* create_expression_tree(const char* rpn)
{
	Node* head = nullptr;

	for(int i = strlen(rpn)-1; i >= 0; i--)
	{
		push(head, rpn[i]);
	}
	
	return head;
}
 
double evaluate_expression(const Node* head)
{
	double result = 0;

	if(!is_operator(head->data))
		return head->data - '0';

	double left = evaluate_expression(head->left);
	double right = evaluate_expression(head->right);

	result = calculate(left, head->data, right);

	return result;
}
