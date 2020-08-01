// This gives wa and has a very small mistake
// have uploaded a new approach within the same file
// will leave it to you guys to find the mistake and  
// that's why I am not removing it from here.

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll t;
	cin >> t;

	while(t--)
	{
		ll n;
		cin >> n;
		
		ll arr[n];
		
		for(ll i = 0; i<n; i++)
			cin >> arr[i];
		
		stack<ll> stack;
		
		stack.push(arr[0]);
		
		for(ll i = 1; i<n; i++)	
		{
			if(stack.empty())
			{
				stack.push(arr[i]);
				continue;
			}
		
			while(stack.empty()==false && arr[i] > stack.top())
			{
				cout << arr[i] << " ";
				stack.pop();					
			}
			
			stack.push(arr[i]);
			
		}	
    
		while(stack.empty()==false)
		{
			cout << "-1 ";
			stack.pop();
		}

			cout << "\n";
	}

}
