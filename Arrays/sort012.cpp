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

    ll a = 0, b = 0,c = 0;

    ll temp;

    for(ll i = 0; i<n; i++)
    {
      cin >> temp;

      if(temp == 0)
        a++;

      else if(temp == 1)
        b++;

      else if(temp == 2)
        c++;
    }

    while(a--)
    {
    cout << 0 << " ";
    }

    while(b--)
    {
    cout << 1 << " ";
    }

    while(c--)
    {
    cout << 2 << " ";
    }

    cout << "\n";

	}

}
