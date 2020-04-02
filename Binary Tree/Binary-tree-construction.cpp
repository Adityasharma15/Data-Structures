#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node
{
  ll data;
  node * left;
  node * right;

  node(ll dataa)
  {
    data = dataa;
    left = NULL;
    right = NULL;
  }
};



bool path( struct Node * nodee, vector<int> &v, int n)
{
    if(nodee == NULL) return false;

    v.push_back(nodee->data);

    if(nodee->data == n) return true;

    if ( (nodee->left && path(nodee->left, v, n)) ||
         (nodee->right && path(nodee->right, v, n)) )
        return true;

    v.pop_back();
    return false;
}



void lca(struct Node* root ,int n1 ,int n2 )
{
    vector<int> v1;
    vector<int> v2;

    path(root, v1, n1);
    path(root, v2, n2);

    int i;

    for(int i = 0; i<v1.size() && i<v2.size(); i++)
    {
        if(v1[i]!=v2[i])
            break;
    }

    cout <<  v1[i-1] << "\n";

}


int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

	ll t;
	cin >> t;

  struct node * head = NULL;

	while(t--)
  {

    ll qq , ww;
    cin >> qq >> ww;

    string s;
    cin >> s;

    ll len = s.length();

    map<ll, node * > mapp;

    node * parent;
    node * leftt;
    node * rightt;

    for(ll i = 0;i<b; i++)
    {
      node * temp = node(s[i]);

      if(head == NULL)
        head = temp;

      map[s[i]] = temp;

      ll xx = m-1;

      if( (xx/2) >=0)
          map[xx/2].left = map[s[i]];

      xx--;

      if( (xx/2) >=0)
          map[xx/2].left = map[s[i]];
    }

    lca(head, qq, ww);

	}

}
