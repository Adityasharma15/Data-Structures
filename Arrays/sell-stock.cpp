// Stock buy and sell
// https://www.geeksforgeeks.org/stock-buy-sell/

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

      for(ll i= 0; i<n ;i++)
        cin >> arr[i];

      vector<pair<ll,ll>> profits;

      ll i = 0;
      while(i<(n-1))
      {
          while(i<(n-1) && arr[i] > arr[i+1])
          {
            i++;
          }

          ll buy = i;

          // the local minima is at last day
          // you can not make any profit.
          if(buy == (n-1))
            break;

            while( i<(n-1) && arr[i]< arr[i+1])
            {
              i++;
            }

          ll sell = i;
          profits.push_back({buy, sell});
        }

        if(profits.size() == 0)
          cout << "No Profit\n";

        else
        {
          for(auto i: profits)
            cout << "(" << i.first << " " << i.second << ") ";

            cout << "\n";
        }
	}
  return 0;
}
