// Time Complexity: O(n)
// Space Complexity: O(1)
// Find Missing And Repeating
// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

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

    for(ll i = 0; i<n; i++)
      cin >> arr[i];

    // We will use index of the array as hash
    // for every value that occurs, mark the index
    // of its value-1 as negative of whatever is stored
    // already to mark its attendance.
    // if attendance is marked twice(already negative), its repeated
    // if attendance isn't marked(positive even after array traversal),
    // its absent.

    ll repeating=0;
    for(ll i = 0; i<n; i++)
    {
      ll temp = arr[i];

      if(temp<0)
        temp *= -1;

      // already marked,  
      if(arr[temp-1] < 0)
        repeating = temp;

      else
        arr[temp-1] *= -1;
    }

    ll i;
    for(i = 0; i<n; i++)
    {
      if(arr[i] > 0)
        break;
    }

    cout << repeating << " " << (i+1) << "\n";
	}
  return 0;
}
