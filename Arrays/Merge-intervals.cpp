#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool comp( pair<ll,ll> p, pair<ll,ll> p2)
{
  if(p.first == p2.first)
    return p.second > p2.second;

    return p.first < p2.first;
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

    vector<pair<ll,ll>> vec;

    for(ll i = 0; i<n; i++)
    {
      ll a, b;
      cin >> a >> b;
      vec.push_back( {a,b});
    }

    sort(vec.begin(), vec.end(), comp);

    // for(auto i: vec)
    // cout << i.first << " " << i.second << " ";
    //
    // cout << "\n";
    ll first = vec[0].first;
    ll second = vec[0].second;
    vector<pair<ll,ll>> ans;

    for(ll i = 1; i<n; i++)
    {
        if(second >= vec[i].first)
        {
          second = max(vec[i].second, second);
          vec[i] = {-1, -1};
        }

        else
          {
            ans.push_back({first, second});
            second = vec[i].second;
            first = vec[i].first;
          }
    }

    ans.push_back({first, second});

    // for(auto i:vec)
    // {
    //   if(i.first!= (-1) && i.second!=(-1))
    //     ans.push_back(i);
    // }

    // cout << ans.size() << "\n";

    for(auto i: ans)
      cout << i.first << " " << i.second << " ";

    cout << "\n";
	}

  return 0;
}
