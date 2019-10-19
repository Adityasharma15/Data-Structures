#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * head;
	node * left;
	node * right;
};

void preorder(node * head)
{
	if(head==NULL)
	return;
	
	cout << head->data << endl;
	
	preorder(head->left);
	preorder(head->right);
}


void postorder(node * head)
{
	if(head==NULL)
	return;																	
	
	                                                                 
	postorder(head->left);    
	postorder(head->right);
	cout << head->data << endl;                                         
}

void inorder(node * head)
{
	if(head == NULL)
	return;
	
	inorder(head->left);
	cout << head->data << endl;
	inorder(head->right);
}














node * createnewnode(node * head, int data)
{
  node * temp = new node();
  
  temp->data = data;
  temp->right = NULL;
  temp->left = NULL;
  
  return temp;

}

node * insert(node * head, int data)
{
	node * temp = createnewnode(head, data);
	
	if(head==NULL)
		head=temp;
	
	else if(data<head->data)
	insert(head->left, data);
	
	else if(data>head->data)
	insert(head->right, data);
	
	return head; 
}

int main()
{
	node * head = NULL;
	
	long long int n;
	cin >> n;
	
	while(n--)
	{
		long long int x;
		cin >> x;
		head = insert(head, x);
	}
	
	preorder(head);
}
