#include<bits/stdc++.h>
using namespace std;

 //incomplete
 
struct node
{
	int data;
	node * left;
	node * right;
};

node* newNode(int data)
{
	node * temp = new node();
	
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

node * add(node * head , int data)
{
	if(head == NULL)
	{
		head = newNode(data);
		return head;
	}
	
	else if (data <= head->data )
	{
		head->left = add(head->left,data);
	}
	
	else if(data > head->data)
	{
		head->right = add(head->right, data);
	}
	
	return head;
}

int findheight(node * head)
{
	if(head==NULL)
	return -1;
	
	int leftheight = findheight(head->left);
	
	int rightheight = findheight(head->right);
	
	return max(leftheight , rightheight) + 1;
}

int main()
{
	node * head = NULL;
	head = add(head , 10);
	head = add(head , 20);
	head = add(head , 200);
	head = add(head , 30);
	
	cout << "Height " << findheight(head) << endl;
}
