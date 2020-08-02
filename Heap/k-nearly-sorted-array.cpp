// Time Complexity - O(n*logk), Using insertion sort would have
// Complexity O(n*k);

// Nearly Sorted Algorithm
// https://www.geeksforgeeks.org/nearly-sorted-algorithm/

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
    ll n, k;
    cin >> n >> k;
    priority_queue<ll, vector<ll> , greater<ll>> min_heap;

    for(ll i = 0; i<k; i++)
    {
      ll temp;
      cin >> temp;
      min_heap.push(temp);
    }

    // extract the min from the curr k elements and put it
    for(ll i = k; i<n; i++)
    {
      ll temp;
      cin >> temp;
      min_heap.push(temp);
      cout << min_heap.top() << " ";
      min_heap.pop();
    }

    while(!min_heap.empty())
    {
      cout << min_heap.top() << " ";
      min_heap.pop();
    }
    cout << "\n";
	}

  return 0;

}
