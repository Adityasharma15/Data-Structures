#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

  ll n;
  cin >> n;

  vector<ll> vec(n);

  for(ll i = 0; i<n; i++)
    cin >> vec[i];

  ll k = log2(n) + 1;

  vector<vector<ll>> st(n, vector<ll>(k));

  for(ll i= 0; i<n; i++)
    st[i][0] = vec[i];

  for(ll j = 1; j<k; j++)
  {
    for(ll i = 0; (i + (1<<(j-1)))< n ; i++)
    {
      st[i][j] = min( st[i][j-1] , st[ i + (1<<(j-1))][j-1]);
    }
  }

  // for(ll j = 0; j<n; j++)
  // {
  //   for(ll i = 0; i< k ; i++)
  //   {
  //     cout << st[j][i] << " ";
  //   }
  //   cout <<"\n";
  // }


  ll q;
  cin >> q;

  while(q--)
  {
    ll l, r;
    cin >> l >> r;
    ll ans = INT_MAX;

    for(ll i = k; i>=0; i--)
    {
        if( (1<<i) <=  ((r-l)+1))
        {
          ans =  min(ans, st[l][i]);
          l += (1<<i);
         }
    }

    cout << ans << "\n";
  }

  return 0;
}
