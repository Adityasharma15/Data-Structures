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

    ll arr[n];

    ll sum = 0;

    for(ll i = 0; i<n ; i++)
    {
      cin >> arr[i];
      sum += arr[i];
    }

    ll cursum = 0, temp, ans = -1;

    for(ll i = 0; i<n; i++)
    {
      temp = sum - arr[i] - cursum;
      
      if(cursum == temp)
        {
          ans = i + 1;
          break;
        }

        cursum += arr[i];
    }

    cout << ans << "\n";

	}

}
