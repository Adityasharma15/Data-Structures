// Next larger element
// https://practice.geeksforgeeks.org/problems/next-larger-element/0

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

     stack<pair<ll,ll>> stackk;
     vector<ll> arr(n,-1);

     for(ll i = 0; i<n; i++)
     {
        ll temp;
        cin >> temp;

        if(!stackk.empty())
        {
            pair<ll,ll> top = stackk.top();
            while(top.first<temp)
            {
              arr[top.second] = temp;
              stackk.pop();

              if(stackk.empty())
                break;

              top = stackk.top();
            }
        }

        stackk.push({temp, i});
     }

     for(ll i = 0; i<n; i++)
      cout << arr[i] << " ";

     cout << "\n";
	}

  return 0;
}
