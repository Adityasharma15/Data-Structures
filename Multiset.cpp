#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

		multiset<ll> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(2);

    ms.erase(1);

    for(auto i:ms)
      cout << i <<"\n";

  return 0;
}
