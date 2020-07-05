#include <iostream>
#include "vector.hpp"

using namespace std;

int main()
{
	Vector<char> v;
	v.push_back('a');
	v.push_back('a');
	v.push_back('a');
	cout << v.get_size() << endl;
	cout << v[0]<< endl;
	cout << v[v.get_size()-1]<< endl;
	v.push_front('b');
	cout << v.get_size() << endl;
	cout << v[0]<< endl;
	cout << v[v.get_size()-1]<< endl;
	v.pop_back();
	cout << v.get_size() << endl;
	cout << v[0]<< endl;
	cout << v[v.get_size()-1]<< endl;
	v.pop_front();
	cout << v.get_size() << endl;
	cout << v[0]<< endl;
	cout << v[v.get_size()-1]<< endl;
	return 0;
}