// https://www.spoj.com/problems/THRBL/
// SPOJ SOLUTION
// SPOJ Problem THRBL - Catapult that ball

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

  ll n, q;
  cin >> n >> q;

  vector<ll> vec(n);

  for(ll i = 0; i<n ; i++)
    cin >> vec[i];

  ll k = log2(n) + 1;

  vector<vector<ll>> st(n, vector<ll>(k));

  for(ll i = 0; i<n ; i++)
  {
    st[i][0] = vec[i];
  }

  for(ll j = 1; j<k; j++)
  {
    for(ll i = 0; (i + (1<<(j-1)))<n; i++)
    {
      st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
    }
  }

  ll ans = 0;

  ll a,b;

  while(q--)
  {
    cin >> a >> b;
    a--;
    b--;

    ll l = min(a,b), r = max(a,b);
    r--;

    ll value = vec[l];
    ll temp = INT_MIN;

    for(ll i = k; i>=0; i--)
    {
      if((1<<i) <= ((r-l)+1))
      {
        temp = max(temp, st[l][i]);
        l+=(1<<i);
      }
    }

    if(temp<=value)
      ans++;
  }

  cout << ans << "\n";

  return 0;
}
