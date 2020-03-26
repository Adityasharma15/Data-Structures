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

ll countleaves( struct node * nodee)
{
  if(nodee == NULL)
    return 0;

  if(nodee->left == NULL && nodee->right == NULL)
    return 1;

    return (countleaves(nodee->right) + countleaves(nodee->left));
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

        cout << countleaves(head) << "\n";
	}

}
