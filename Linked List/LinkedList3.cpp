//Add node at a particular position.

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node * next;
};

node* head;
//Never declare global variable head = 0 otherwise it will remain 0
// But make it 0 in main so it start with NULL

void add(int x , int n)
{
	node * temp = new node;
	
	temp->data = x;
	temp->next = NULL;
	
	node *temp2 = head;
	
	if(n==1)
	{
		
	}
	
	for(int i=0 ; i<n-2 ; i++)
	{
		temp2 = temp2->next;
	}
	
}

void print()
{
	node * temp = head;
	
	while(temp!=NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
	
}

int main()
{
	head = NULL;
	add(2,4);
	print();
	
	
}
