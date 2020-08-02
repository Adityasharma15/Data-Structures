// Kth largest element in a stream
// https://www.geeksforgeeks.org/kth-largest-element-in-a-stream/

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

    ll k, n;
    cin >> k >> n;

    priority_queue< ll, vector<ll> , greater<ll> > min_heap;
    for(ll i = 0; i<n; i++)
    {
      ll temp;
      cin >> temp;

      if(min_heap.size() < (k-1))
      {
        cout << "-1 ";
        min_heap.push(temp);
        continue;
      }

      // if on adding this element, k elements will be complete
      else if(min_heap.size() == (k-1))
      {
        min_heap.push(temp);
        cout << min_heap.top() << " ";
      }

      else if(min_heap.size()==k)
      {
        // if this element is greater, then this will be used in
        // the heap and thus discard the top element.
        if(temp> min_heap.top())
        {
          min_heap.pop();
          min_heap.push(temp);
        }

        else
        {
          min_heap.push(temp);
          min_heap.pop();
        }

        cout << min_heap.top() << " ";
      }

    }
      cout << "\n";
	}
  return 0;
}
