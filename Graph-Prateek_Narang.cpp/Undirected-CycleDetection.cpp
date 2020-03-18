#include<bits/stdc++.h>
#define ll long long

using namespace std;

class Graph
{
  ll V;
  list<ll> * adjlist;

public:
  Graph(ll v)
  {
    V = v;
    adjlist = new list<ll>[V];
  }

  void add(ll a, ll b)
  {
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
  }

  bool CycleDetection( bool visited[], ll parent[], ll i)
  {
    visited[i] = true;

    for(auto j: adjlist[i])
    {
        if(j == i)
          return true;

        if(visited[j] && parent[i]!= j)
        {
          return true;
        }

        if(!visited[j])
        {
          visited[j] = true;
          parent[j] = i;

          if(CycleDetection(visited, parent, j))
            return true;
        }
    }

    return false;
  }

  bool CycleDetectionUtil()
  {
    bool visited[V];
    ll parent[V];

    memset(visited , false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    parent[0] = 0;

    for(ll i = 0; i<V; i++)
    {
      if(!visited[i])
      {
      if(CycleDetection(visited, parent ,i))
        return true;
      }  
    }
    return false;
  }

};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

  ll t;
  cin >> t;

  while(t--)
  {

      ll v , e;
      cin >> v >> e;

      Graph g(v);

      ll a, b;

      for(ll i = 0; i<e; i++)
      {
        cin >> a >> b;
        g.add(a, b);
      }

      if(g.CycleDetectionUtil())
        cout << 1 << "\n";

      else
        cout << 0 << "\n";
  }

}
