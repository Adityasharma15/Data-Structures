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

		for(ll i = 0; i<n; i++)
			cin >> arr[i];

		ll maxx = -1;

		std::vector<ll> v;

		for (ll i = n-1; i >=0 ; i--)
		{

				if(arr[i] >= maxx)
					{
						v.push_back(arr[i]);
						maxx = max(maxx, arr[i]);
					}
		}

		for(ll i = v.size() - 1; i>=0; i--)
			cout << v[i] << " ";

			cout << endl;


	}


}
