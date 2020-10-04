//Arrays with sum equal to 0 or k


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

    unordered_map<ll,ll> um;
    um[0]++;

    ll x, sum = 0, ans = 0;

    for(ll i = 0;i<n; i++)
    {
        cin >> x;
        sum += x;

        if(um.find(sum)!=um.end())
        {
          ans+= um[sum];
        }

        um[sum]++;
    }

      cout << ans << "\n";
	}

  return 0;
}
