#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll t;
	cin >> t;

	while(t--)
	{
		ll n, m;
		cin >> n >> m;
		
		ll temp, arr[n];
		
		unordered_map<ll,ll> um;
		
		for(ll i = 0; i<n; i++)
		{
			cin >> arr[i];
			um[arr[i]]++;	
		}	
    
		for(ll i = 0; i<m; i++)
		{
			cin >> temp;
			
			while(um[temp]--)
			{
				cout << temp << " ";
			}
		}
		
		for(ll i = 0; i<n; i++)
		{
			temp = arr[i];
				
			while(um[temp]--)
			{
				cout << temp << " ";	
			}	
		}	
		
		
			cout << "\n";
	}

}
