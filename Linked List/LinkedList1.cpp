// Add an element at start of the linked list

#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	node * next;
};

node * head;

void print()
{
	node * temp = head;
	while(temp!=NULL)
	{
		cout << temp->data << endl;
 		temp = temp->next;		
	}
	
} 


void add(int x)
{
	node * temp = new node;
	
	temp->data = x;
	temp->next = head;
    head = temp;
}

int main()
{
	head = NULL;
	int n , a ;
	cout << "Enter the number of elements to be added and the data" << endl;
	cin >> n;
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a;
		add(a);
		print();
		
	}	
}
