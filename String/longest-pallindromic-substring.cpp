// Longest Palindrome in a String
// https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

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

    string s;
    cin >> s;

    ll n = s.size();
    ll max_len = 1;
    ll start = 0, end;

    for(ll i = 0; i<n; i++)
    {
      ll left = i, right = i+1;

      // for even
      while(left >= 0 && right <n)
      {
        if( s[left] == s[right])
        {
            if(max_len < (right - left) +1)
              {
                start = left, end = right;
                max_len = (right - left) + 1;
              }
        }

        else
          break;

          left--;
          right++;
      }

      left = i-1, right = i+1;

      //for odd
      while(left >= 0 && right <n)
      {
        if( s[left] == s[right])
        {
          if(max_len < (right - left) +1)
            {
              start = left, end = right;
              max_len = (right - left) + 1;
            }
        }

        else
          break;

          left--;
          right++;
      }
    }

    for(ll i = start ; i<start + max_len; i++)
      cout << s[i];

    cout << "\n";
  }
  return 0;
}
