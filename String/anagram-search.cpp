// Count Occurences of Anagrams
// https://www.geeksforgeeks.org/anagram-substring-search-search-permutations/

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

    string text, pattern;
    cin >> text >> pattern;
    ll n = text.size(), m = pattern.size();

    // We will use modified Rabin Karp Algorithm

    vector<ll> pattern_hash(27,0);
    vector<ll> window_hash(27,0);

    for(ll i = 0; i<m; i++)
    {
      pattern_hash[pattern[i] - 'a']++;
      window_hash[text[i] - 'a']++;
    }

    ll pattern_found_count = 0;
    for(ll i = m; i<=n; i++)
    {
        if(pattern_hash == window_hash)
            pattern_found_count++;

        if(i == n)
          break;

        window_hash[text[i-m] - 'a']--;
        window_hash[text[i] - 'a']++;
    }

    cout << pattern_found_count << "\n";
	}
  return 0;
}
