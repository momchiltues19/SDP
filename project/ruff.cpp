#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

const int MAX_NODES=100;

void InitGraph(int arr[MAX_NODES][MAX_NODES],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"arr["<<i<<"]["<<j<<"]=";
			cin>>arr[i][j];
		}
	}
}
void PrintGraph(int arr[MAX_NODES][MAX_NODES],int n)
{
	cout<<setw(2);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<setw(2);
		}
		cout<<endl;
	}
} 

struct Trio
{
	int unvisited;
	int distance;
	int previous;
};

int Sum(Trio t[], int n)
{
	int sum = 0;
	
	for(int i = 0; i < n; i++)
	{
		sum += t[i].unvisited;
	}

	return sum;
}

struct Node
{
	int data;
	vector<Node*> next;
};

Node* Allocate(int x)
{
	Node* ptr = new Node;
	ptr->data = x;
	return ptr;
}

Node* Dijkstra(int arr[][6], Trio t[], int start, int n)
{
	
	for(int i = 0; i < n; i++)
	{
		t[i].unvisited = i;
		t[i].previous = -1;
		if(i == start)
		{
			t[i].distance = 0;
		}
		else
		{
			t[i].distance = 1000;
		}
	}
	int current, min;
	while(-5 != Sum(t,5))
	{  
		for(int i = 0; i < n; i++)
		{
			if(t[i].unvisited != -1)
			{
				min = t[i].distance;
			    current = i;
			    break;
			}
		}
		for(int i = 0; i < n; i++)
		{
			if(t[i].unvisited != -1 && t[i].distance < min)
			{
				min = t[i].distance;
			    current = i;
			}	
		}
		for(int i = 0; i < n; i++)
		{
			if(arr[current][i] != -1 && t[i].unvisited != -1)
			{
				if(arr[current][i] + t[current].distance < t[i].distance)
				{
					t[i].distance = arr[current][i] + t[current].distance;
					t[i].previous = current;
				}
			}
		}
		t[current].unvisited = -1;	
	}
}

/*
void Print(Node* root) 
{
	
}
*/

int main()
{
	int arr[6][6]=
	{{-1,1,7,-1,-1,2},
	 {1,-1,-1,-1,4,8},
	 {7,-1,-1,9,-1,8},
	 {-1,-1,9,-1,6,5},
	 {-1,4,-1,6,-1,6},
	 {2,8,8,5,6,-1}};
	Trio t[6];
	int start = 0;
	int n = 6;
	Dijkstra(arr, t, start, n);
	
	Node* root = NULL;
	
}