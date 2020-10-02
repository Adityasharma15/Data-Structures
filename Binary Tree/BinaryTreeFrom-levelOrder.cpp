#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node
{
  ll data;
  node * left;
  node * right;

  node(ll x)
  {
    data = x;
    left = NULL;
    right = NULL;
  }

};







int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

  ll t;
  cin >> t;

  while(t--)
  {
  ll a, b;
  cin >> a >> b;

  ll x;

  vector<ll> v;
	  
	  

  while(1)
  {
    cin >> x;

    if(x==NULL)
    break;

    v.push_back(x);
  }

    // ll len = s.length();
    //
    // vector<ll> v(len);
    //
    // for(ll i = 0; i<len; i++)
    // {
    //   v[i] = s[i];
    // }

    for(auto i:v)
      cout << i << endl;

	}

}
