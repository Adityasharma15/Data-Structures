// https://www.codechef.com/problems/FRMQ

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

  vector<ll> arr(n);

  for(ll i = 0; i<n; i++)
    cin >> arr[i];

  ll k = log2(n) + 1;

  // sparse table
  vector<vector<ll>> st(n, vector<ll>(k));

  for(ll i = 0; i<n; i++)
    st[i][0] = arr[i];

  for(ll i = 1; i<k; i++)
  {
    for(ll j = 0; (j+(1<<(i-1)))<n; j++)
    {
      st[j][i] = max(st[j][i-1], st[j + (1<<(i-1))][i-1]);
    }
  }

  ll m;
  cin >> m;

  ll x, y;
  cin >> x >> y;

  ll ans = 0;

  ll l, r;

  while(m--)
  {
    l = min(x,y);
    r = max(x,y);
    ll tempans = INT_MIN;

    for(ll i = k; i>=0; i--)
    {
        if((1<<i) <= ((r-l) +1))
        {
            tempans = max(tempans, st[l][i]);
            l += (1<<i);
        }
    }

    ans+=tempans;
    x = (x+7)%(n-1);
    y = (y+11)%n;
  }

  cout << ans << "\n";

  return 0;

}
