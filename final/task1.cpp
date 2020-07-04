#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int calculate(string);
int to_int(char);

int main()
{
	cout << calculate("((2$3)@(3$4))") << endl;

	return 0;
}

int calculate(string expression)
{
	stack<char> st;
	int result = 0;
	for(int i = 0; i < expression.size(); i++)
	{
		st.push(expression[i]);
	}

	while(!st.empty())
	{
		if(st.top() == '$')
		{
			st.pop();
			result = min(to_int(st.top()), result);
		}
		else if(st.top() == '@')
		{
			st.pop();
			result = (to_int(st.top()) + result)%10;
		}
		else if(st.top() >= '0' && st.top() <= '9')
			result = st.top();
		st.pop();
	}
	return result;
}

int to_int(char ch)
{
	return ch - '0';
}