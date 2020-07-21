// Palindromic Array
// https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

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
    {
      cin >> vec[i];
    }

    ll l = 0, r = n-1;
    ll merge = 0;
    while(l<r)
    {
      if(vec[l] == vec[r])
      {
        l++;
        r--;
      }

      else if(vec[l] < vec[r])
      {
        vec[l+1] += vec[l];
        l++;
        merge++;
      }

      else
      {
        vec[r-1] += vec[r];
        r--;
        merge++;
      }
    }
    cout << merge << "\n";
	}
  return 0;
}
