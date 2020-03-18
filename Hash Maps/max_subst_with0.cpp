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
	
	unordered_map<ll> map;
	
	ll sum = 0, length = 0;
	
	for(ll i = 0; i<n; i++)
	{
		cin >> arr[i];
		sum+= arr[i];
		
		if(map[sum])
			length =max((map[sum] - i )) , length);
			
		else
			map[sum] = i;			
	}	
    
	cout << length << "\n";

	}

}
