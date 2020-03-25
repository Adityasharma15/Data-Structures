#include<bits/stdc++.h>
#define int long long
using namespace std;

void topSortUtil(bool * visited, int v, vector<int> adj[], int i,stack<int> s)
{
    visited[i] = true;

    for(auto j: adj[i])
    {
        if(!visited[j])
          topSortUtil(visited, v, adj, j, s);

    }

    s.push(i);
    return;
}


int * topSort(int v, vector<int> adj[])
{
  bool visited[v];
  memset(visited, false, sizeof(visited));

  int * arr;
  arr = new int[v];

  stack<int> s;

  for(int i = 0; i<v; i++)
  {
      if(!visited[i])
        topSortUtil(visited, v, adj, i, s);
  }

  for(int z = 0; z<v && !s.empty(); z++)
  {
    arr[z] = s.top();
    s.pop();
  }

  return arr;
}

int main()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--)
  {
      int n, e;
      cin >> n >> e;

      vector<int> adj[n];

      int u, v;

      for(int i = 0 ; i<e; i++)
          {
            cin >> u >> v;
            adj[u].push_back(v);
          }

      int * res = topSort(n, adj);

      for(ll i = 0; i<n; i++)
          cout << res[i] << " ";

          cout << "\n";

	}

  return 0;
}
