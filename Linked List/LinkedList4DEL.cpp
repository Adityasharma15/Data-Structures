#include<bits/stdc++.h>
using namespace std;

struct node
{
int data;
node * next ;
	
};

node * head;


void add(int x)
{

	
	node * temp1 = new node();
	
	temp1->data = x;
	temp1->next = head;
	
	head = temp1;	
}


void print()
{
	node* t5=head;
	
	while(t5!=NULL)
	{
		cout << t5->data << " ";
		t5=t5->next;
		
	}
}


void Delete(int n)
{
	node * t;
	if(n==1)
	{
		
		head = head->next;
	}
	
	else
	{
	
	t = head;
	
	for(int i=0;i<n-2;i++)
	{
		t=t->next;
	}
	 
	 node*t1 =t->next;
	 
	 t->next=t1->next; 
	
	}
}

int main()
{
	
	head = NULL;
	int n ;
	
	add(1);
	add(2);
	add(3);
	add(4);
	add(5);
	add(6);
	cout << "Enter node to delete" << endl;
	cin >> n;
	Delete(n);
	print();
    
}
