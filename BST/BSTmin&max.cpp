#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data ;
	node * left;
	node * right;
};

node * createNode(int data)
{

node * temp = new node();

temp->data = data;
temp->right= NULL;
temp->left = NULL;

return temp;
}

node * add(node * head , int data)
{
	if(head == NULL)
	{
		head = createNode(data);
		return head;
	}
	
	else if(data <= head->data)
	{
		head->left = add(head->left , data);
	}
	
	else if ( data > head->data )
	{
		head -> right = add(head->right , data);
	}
	
	return head;
}


int max(node * head)
{
	if(head->right == NULL)
	{
	 return head->data;
	}
	
	else
	{
		head=head->right;
		return max(head);
	}
}

int min(node * head)
{
	if(head->left == NULL)
	{
	  return head->data;
	}
	
	else
	{
		head = head->left;
		return min(head);
	}
	
}


int main()
{
	node * head = NULL;
	
	int n;
	
	cout << "Enter elements of tree" << endl;
	
	do{
		cin >> n;
		head=add(head , n);
	}while(n!=0);
	
	cout << "max is " << max(head) << endl;
	cout << "min is " << min(head) << endl;
}
