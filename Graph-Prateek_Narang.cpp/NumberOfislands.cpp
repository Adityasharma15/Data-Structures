#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool visited[101][101];

bool isSafe(vector<ll> v[], ll ROW, ll COL , ll row, ll col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (v[row][col] && !visited[row][col]);
}

ll findislandsUtil(vector<ll> v[], ll n, ll m, ll x, ll y, ll count)
{
    visited[x][y] = true;

    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for(ll i = 0; i<8; i++)
    {
      if(isSafe(v, n, m, (x + rowNbr[i]), (y + colNbr[i])))
      {
        findislandsUtil(v, n ,m , (x + rowNbr[i]), (y + colNbr[i]) , count);
      }
    }
}


ll findislands(vector<ll> v[], ll n, ll m)
{
    ll count = 0;

    for(ll i = 0; i<n; i++)
    {
      for(ll j = 0; j<m; j++)
      {
          if(!visited[i][j] && v[i][j] == 1)
            {
              findislandsUtil(v, n ,m , i, j , count);
              ++count;
      }     }
    }

    return count;

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

    ll n, m;
    cin >> n >> m;

    memset(visited, false, sizeof(visited));

    vector<ll> v[n];

    for(ll i = 0; i<n; i++)
    {
      vector<ll> temp(m);
      v[i] = temp;

      for(ll j = 0; j<m; j++)
          cin >> v[i][j];
    }

    ll ans = findislands(v, n,m);

    cout << ans << "\n";

	}

}
