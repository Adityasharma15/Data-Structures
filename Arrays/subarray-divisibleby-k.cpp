// Longest subarray with sum divisible by K
// https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/

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
    ll n, k;
    cin >> n >> k;
    // mod stores mod k of elemenst 0...i;
    vector<ll> mod(n);
    //we store the value of mod k found so far.
    // vector<ll> modhash(10000000, -1);
    unordered_map<ll,ll> modhash;

    ll tempmod = 0;
    for(ll i = 0; i<n ;i++)
    {
      ll temp;
      cin >> temp;
      tempmod+=temp;
      mod[i] = (tempmod%k + k)%k;
    }

    ll maxlen = 0;
    // If mod == 0, whole subbarray can be taken
    // if mod == temp and temp has occurred earlier, we can remove
    // that part and them mod will become 0;
    for(ll i = 0; i<n; i++)
    {
        // cout << modhash[2] << "\n";

      if(mod[i] == 0)
        maxlen = max(maxlen, i+1);

      if( modhash.find(mod[i]) != modhash.end())
        maxlen = max(maxlen , i - modhash[mod[i]]);

      else
        modhash[mod[i]] = i;
    }

    cout << maxlen << "\n";
	}
  return 0;
}
