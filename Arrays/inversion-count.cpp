// Inversion of array
// https://www.geeksforgeeks.org/counting-inversions/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

// ll mergesortfunc(vector<ll> &arr, vector<ll> temp, ll left, ll right);
ll mergesortmod(vector<ll> &arr, vector<ll> temp, ll left, ll mid, ll right);

ll mergesortfunc(vector<ll> &arr, vector<ll> temp, ll left, ll right)
{
  ll inversion_count = 0;
  ll mid;
  if(left<right)
  {
    mid = (left + right)/2;
    inversion_count += mergesortfunc(arr, temp, left, mid);
    inversion_count += mergesortfunc(arr, temp, mid+1, right);
    // cout << left << " " << mid << " " << right << "\n";

    inversion_count += mergesortmod(arr, temp, left, mid+1 , right);
    // cout << inversion_count << "\n";
  }
    return inversion_count;
}


ll mergesortmod(vector<ll> &arr, vector<ll> temp, ll left, ll mid, ll right)
{
  // we are using ptrs of left & rigth because original
  // left & right will be needed to put this sorting into
  // our original array.
  ll leftptr = left, rightptr = mid;
  ll inversion_count = 0;

  // tempptr corresponds with the sorted array we are making.
  ll tempptr = left;

  while(leftptr<=(mid-1) && rightptr <= right )
  {
    // cout << "&\n";
      if(arr[leftptr] <= arr[rightptr])
      {
        // cout << "#\n";
        // cout << arr[leftptr] << " " << arr[rightptr] << "\n";
        temp[tempptr++] = arr[leftptr++];
      }

      else
      {
        temp[tempptr++] = arr[rightptr++];

        // cout << "*";
        // if ith element from left subarray is greater
        // than some element from right subarray, all the
        // element  s to the right of ith element from left subarray
        // will also be greater than that element from right subarray
        inversion_count += (mid - leftptr);
      }
  }

  // one will be empty and other will still have elements
  // we need to append the remaining values at the end linewise
  // as it is clear they will be max & also sorted
  while(leftptr<=(mid-1))
  {
    temp[tempptr++] = arr[leftptr++];
  }

  while(rightptr<=right)
  {
    temp[tempptr++] = arr[rightptr++];
  }

  // // time to perform the changes in the main array
  for(ll i = left; i<=right ; i++)
  {
    arr[i] = temp[i];
  }

  return inversion_count;
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

    for(ll i = 0; i<n; i++)
      cin >> arr[i];

    vector<ll> temp(n);
    ll ans = mergesortfunc(arr, temp, 0,n-1);
    cout << ans << "\n";
  }
  return 0;
}
