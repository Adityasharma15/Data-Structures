#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
  ll t;
  cin >> t;

  while(t--)
  {
    string s, s1;

    cin >> s >> s1;


    ll len = s.length();
    ll len1 = s1.length();


    ll mat = 0, umat = 0;

    ll hash[26];

    memset(hash, 0, sizeof(hash));

    for(ll j = 0; j<len; j++)
      hash[s[j] - 'a'] = 1;

    for(ll i = 0; i<len1; i++)
    {
      if(hash[s1[i]-'a']==1)
        {
          hash[s1[i] - 'a'] = -1;
        }

      else
      {
          if(hash[s1[i]-'a']!=(-1))
            hash[s1[i] - 'a'] = 2;
      }
    }

    string ans = "";

    for(ll i = 0; i<26; i++)
    {
      if(hash[i] == 1 || hash[i] == 2)
      {
        ans += char(i + 'a');
      }
    }

    cout << ans << "\n";
  }

}
