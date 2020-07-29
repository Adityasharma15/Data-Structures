// Maximum length Bitonic Subarray
// https://practice.geeksforgeeks.org/problems/maximum-length-bitonic-subarray/0

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

	ll t;
	cin >> t;
	while(t--)
  {
    ll n;
    cin >> n;
    vector<ll> arr(n);

    for(ll i = 0; i<n; i++)
      cin >> arr[i];

    vector<ll> inc(n,1), dec(n,1);

    for(ll i = 0 ; i<(n-1); i++)
    {
      if( arr[i] < arr[i+1] )
        inc[i+1] = inc[i] + 1;
    }

    for(ll i = n-1 ; i>0; i--)
    {
      if( arr[i] < arr[i-1] )
        dec[i-1] = dec[i] + 1;
    }

    ll maxx = 0;
    for(ll i = 0; i<n; i++)
    {
      // -1 for the current element as it is count
      // both for dec & inc
      maxx = max(maxx, (inc [i]+ dec[i]) - 1);
    }

    cout << maxx << "\n";
	}

  return 0;

}
