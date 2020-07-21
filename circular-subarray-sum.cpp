// Max Circular Subarray Sum
// https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll max_kedans(vector<ll> arr)
{
  ll max_sum = INT_MIN;
  ll curr_sum = 0;
  for(ll i = 0; i<arr.size(); i++)
  {
    curr_sum+=arr[i];
    max_sum = max(curr_sum, max_sum);

    if(curr_sum<0)
      curr_sum = 0;
  }
  return max_sum;
}

ll min_kedans(vector<ll> arr)
{
  ll min_sum = INT_MAX;
  ll curr_sum = 0;
  for(ll i = 0; i<arr.size(); i++)
  {
    curr_sum+=arr[i];
    min_sum = min(curr_sum, min_sum);

    if(curr_sum>0)
      curr_sum = 0;
  }

  return min_sum;
}

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
    ll totalsum = 0;
    ll max_element = INT_MIN;
    bool allnegative = true;
    for(ll i = 0; i<n; i++)
    {
         cin >> arr[i];
         totalsum+=arr[i];
         max_element = max(max_element, arr[i]);

         if(arr[i] >= 0) allnegative = false
    }

    ll max_subarray_sum = max_kedans(arr);
    ll min_subarray_sum = min_kedans(arr);

    // this is a corner case
    if(allnegative)
      cout << max_element << "\n";

    // this is using wraper functionality of circular
    // array, we can skip the part of min sum and
    // include rest or the max part of linear array
    // without circular property, whichever greater.
    else
      cout << max(max_subarray_sum, (totalsum - min_subarray_sum)) << "\n";
  }
  return 0;
}
