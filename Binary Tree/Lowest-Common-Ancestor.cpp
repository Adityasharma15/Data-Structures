#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node
{
  ll data;
  struct node * left;
  struct node * right;

  node(ll x)
  {
    data = x;
    left = NULL;
    right = NULL;
  }

};

bool path( struct node * nodee, vector<ll> v)
{
    if(root == NULL) return false;

    v.push_back(nodee->data);

    path(nodee->left, v);
    path(npdee->right,v);

    if(root->data == )

}



ll lca( node * head)
{

    vector<ll> v;

    path(head, v);

}





int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

	ll t;
	cin >> t;

	while(t--)
  {
    node * head = NULL;

    map < ll , node *> m;
    ll n;
    cin >> n;

    while(n--)
    {

    node * parent;
    node * child;

    ll n1, n2;
    char c;

    cin >> n1 >> n2 >> c;

    if(m.find(n1)==m.end())
    {
      parent = new node(n1);
       m[n1] = parent;

       if(head == NULL)
           head = parent;
    }

    else
    {
      parent = m[n1];
    }

    child = new node(n2);

    if(c == 'R')
      parent->right = child;

    else
        parent->left = child;

    m[n2] = child;
    }

        cout << lca(head) << "\n";
	}

}
