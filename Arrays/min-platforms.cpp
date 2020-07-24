// Minimum Platforms
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

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

    // we don't consider much of the stuffs, just look at
    // all the times when some trains arrives or departs and
    // count the number of trains present at the station
    // at that point of time;
    vector<pair<ll,ll>> trains;

    for(ll i = 0; i<(2*n); i++)
    {
      ll temp;
      cin >> temp;

      if(i<n)
        trains.push_back({temp,0});

      else
        trains.push_back({temp,1});
    }

    sort(trains.begin(), trains.end());
    ll arrivals = 0, departures = 0;
    ll curr_trains = 0;

    for(auto i:trains)
    {
      if(i.second == 0)
        arrivals++;

      else
        departures++;

      curr_trains = max(arrivals - departures, curr_trains);
    }

    cout << curr_trains<< "\n";

	}

  return 0;

}
