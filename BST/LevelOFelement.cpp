#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct node
{
  ll int data;
  node*left;
  node * right;
};

node * newnode(ll int data)
{
    node * temp = new node();
    
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

node * addNode(node * head , ll int data)
{
    if(head==NULL)
    {
        head = newnode(data);
        return head;
    }
    
    else if(data > head->data)
        head->right = addNode(head->right,data);
        
    else if(data <= head->data)
     head->left =  addNode(head->left, data);
    
    return head;
}


ll int getLevel(node * head, ll int level , ll int data , ll int lev )
{
    if(head==NULL)
    return 0;
    
    if(head->data == data)
    return level;
    
    if(data > head->data)
    lev = getLevel(head->right , level+1, data , lev);
    
    if(lev!=0)
    return lev;
    
    if(data <= head->data)
    lev = getLevel(head->left, level+1,data,lev);
    
    if(lev!=0)
    return lev;
    
    
}

vector<int> solve (vector<int> A,int N,node * head) {
    // Return an a vector of N elements, ith element representing level of A[i]
    ll int i;
    
    vector<int> Ans;
    
    // for(i =0;i<N;i++)
    //     head = addNode(head,A[i]);
    
    for(i=0;i<N;i++)
        Ans.push_back(getLevel(head,1, A[i],0));

        return Ans;
    
}

int main() {


    node * head = NULL;
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    	head = addNode(head,A[i_A]);
    }

    vector<int> out_;
    out_ = solve(A,N,head);
    cout << out_[0];
    for(int i_out_=1; i_out_<N; i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}
