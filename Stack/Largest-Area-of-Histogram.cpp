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

    ll arr[n];

    for(ll i = 0; i<n; i++)
      cin >> arr[i];

    stack<ll> s;

    ll i  = 0;
    ll area = 0;
    ll top;

    while(i<n)
    {
      if(s.empty() || arr[s.top()]<=arr[i])
        s.push(i++);

      else
      {
        top = s.top();
        s.pop();

        if(!s.empty())
          area = max((arr[top] * (i - s.top() - 1) ), area);

        else
          area = max( (arr[top]*i), area);
      }

    }

    while(!s.empty())
    {
      top = s.top();
      s.pop();

      if(!s.empty())
        area = max( (arr[top] * (i - top - 1) ), area);

      else
        area = max( arr[top]*i, area);
    }

    cout << area << "\n";

	}

}
