// Rearrange Array Alternately
// https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form-set-2-o1-extra-space/

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

    vector<ll> vec(n);

    for(ll i = 0; i<n; i++)
      cin >> vec[i];

    ll min_index = 0;
    ll max_index = n-1;
    ll mod = vec[n-1] + 1;

    for(ll i = 0; i<n; i++)
    {
      if(i%2==0)
      {
          vec[i] += ((vec[max_index]%mod)*mod);
          max_index--;
      }

      else
      {
        vec[i] += ((vec[min_index]%mod)*mod);
        min_index++;
      }
    }

    for(ll i = 0; i<n; i++)
      cout << vec[i]/mod << " ";

      cout << "\n";

	}
  return 0;
}
