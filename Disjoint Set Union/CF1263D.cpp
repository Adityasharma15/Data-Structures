#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;

  ll parent[26];

  for(ll i = 0; i<26; i++)
    parent[i] = i;

    string s;

    set<char> sett;

  for(ll i = 0; i<n; i++)
  {
    cin >> s;

    sort(s.begin(), s.end());

    ll messiah = -1;

    for(ll i = 0;i <s.length(); i++)
    {
        if(s[i]=='a')
        {
          messiah = 0;
          break;
        }

        if(parent[s[i] - 'a'] != (s[i] - 'a'))
        {
          messiah = s[i] - 'a';
          break;
        }

    }

    for(ll i = 0;i <s.length(); i++)
    {
      sett.insert(s[i]);

        if(s[i]=='a')
          continue;

            if(messiah== -1)
              parent[parent[s[i] - 'a']] = parent[s[0] - 'a'];

            else
            parent[parent[s[i] - 'a']] = parent[messiah];
    }
  }

  ll ans = 0;

  for(auto i:sett)
  {
    if(parent[i - 'a']==( i - 'a'))
        ans++;

  }

  cout << ans << "\n";

  return 0;

}
