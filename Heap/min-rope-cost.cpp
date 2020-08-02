// Time complexity - O(nlogn) - n in traversing and logn
// in heap operations.

// Minimum Cost of ropes
// https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/


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
    priority_queue<int, vector<int> , greater<int> > min_heap;

    for(ll i = 0; i<n; i++)
    {
      ll temp;
      cin >> temp;
      min_heap.push(temp);
    }

    ll cost = 0;
    while(!min_heap.empty())
    {
      ll first_rope = min_heap.top();
      min_heap.pop();

      ll second_rope = 0;
      if(!min_heap.empty())
      {
        second_rope = min_heap.top();
        min_heap.pop();
      }

      ll curr_cost = first_rope + second_rope;
      cost += curr_cost;
      min_heap.push(curr_cost);

      if(min_heap.size()==1)
        break;
    }

    cout << cost << "\n";
	}
  return 0;
}
