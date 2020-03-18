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

			queue<char> q;

			unordered_map<char, ll > m;

			char temp, temp2;

			bool flag = false;

			while(n--)
			{
					cin >> temp;
					q.push(temp);
					m[temp]++;

					temp2 = q.front();

					while(!q.empty() && flag == false)
					{
						if(m[temp2]==1)
					    {
								cout << temp2 << " ";
								flag = true;
							}

						else
							q.pop();

						temp2 = q.front();
					}

					if(flag == false)
					    cout << -1 << " ";

							flag = false;
			}

			cout << "\n";

	}

}
