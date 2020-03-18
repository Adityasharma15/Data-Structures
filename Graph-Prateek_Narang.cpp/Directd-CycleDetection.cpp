#include<bits/stdc++.h>
#define ll long long

using namespace std;

class Graph
{
    ll V;
    list<ll> *adjlist;

public:
    Graph(ll v)
    {
      V=v;
      adjlist = new list<ll>[V];
    }

    void add(ll u, ll v)
    {
      adjlist[u].push_back(v);
    }

    bool cycleDetection( bool visited[], bool stack[], ll i )
    {
          visited[i] = true;
          stack[i] = true;

          for(auto j: adjlist[i])
          {
            if(stack[j] && visited[j])
              return true;

            if(!visited[j])
              {
                visited[j] = true;
                stack[j] = true;

                if(cycleDetection(visited, stack, j))
                  return true;
              }

              stack[j] = false;
          }

          stack[i] = false;
          return false;
    }

    bool cylceUilt(bool visited[], bool stack[])
    {
          for(ll i = 0; i<V; i++)
          {
            if(cycleDetection(visited, stack, i))
              return true;
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

    ll v, e;
    cin >> v >> e;

    Graph g(v);

    ll a, b;

    for(ll i = 0; i<e; i++)
    {
      cin >> a >> b;
      g.add(a,b);
    }

    bool visited[v];
    bool stack[v];

    memset(visited, false, sizeof(visited));
    memset(stack, false, sizeof(stack));

    if(g.cylceUilt(visited, stack))
      cout << "1" << "\n";

    else
      cout << "0" << "\n";

  }


}
