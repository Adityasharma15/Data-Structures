#include<bits/stdc++.h>
#define ll long long
	
using namespace std;

vector<int> v;

struct node
{
    ll data;
    node * left;
    node * right;

};

node * create_newnode(ll data)
{
    node * temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


node * insert(ll data, node * head)
{
    node * temp = create_newnode(data);

    if(head == NULL)
        head = temp;

    else if(head->data >= data)
        insert(data, head->right);     

    else if(head->data < data)
        insert(data, head->left);

    return head;    
}

void print_inorder(node * head)
{
    if(head==NULL)
        return;

    print_inorder(head->left);
    cout << head->data;    
    print_inorder(head->right);
}


void vector_updation(node * head)
{
    if(head==NULL)
        return;        


}




int main()
{
    //v.push_back(0);

    node* head = NULL;

    ll n;
    cin >> n;
 
    ll x;

    while(n--)
    {
        cin >> x;
        head = insert(x,head);
    }
    
    print_inorder(head);
}
