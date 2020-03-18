#include<bits/stdc++.h>
#define ll long long
using namespace std;


class Graph
{
  ll V;
  list<int> *adjlist;

public:
  Graph(ll v)
  {
    V = v;
    adjlist = new list<int>[V];
  }

  void add(ll a, ll b)
  {
    adjlist[a].push_back(b);
  }

  ll bfs()
  {
    bool visited[30];
    ll parent[30];
    ll distance[30];

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    memset(distance, -1, sizeof(distance));

    queue<ll> q;

    q.push(0);
    visited[0] = true;
    parent[0] = 0;
    distance[0] = 0;

    ll temp;

    while(!q.empty())
    {
      temp = q.front();
      q.pop();

      for(auto i: adjlist[temp])
      {
        if(!visited[i])
        {
          q.push(i);
          visited[i] = true;
          parent[i] = temp;
          distance[i] = distance[parent[i]] + 1;
        }
      }

    }

        return distance[29];
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
    Graph g(30);

    ll board[30];

    memset(board, -1 , sizeof(board));

		ll x, a, b;
    cin >> x;

    while(x--)
    {
      cin >> a >> b;
      a--;
      b--;
      board[a] = b;
    }

    for(ll node = 0; node<30; node++)
    {
        for(ll dice = 1; dice<=6; dice++)
        {
              if(board[node+dice]>=0)
                {
                  if(node<=29 && board[node+dice]<=29)
                    g.add(node, board[node+dice]);
                  //cout << "node " << node << "  " << board[node + dice] << endl;
                }
              else
                {
                  if(node<=29 && (node+dice)<=29)
                    g.add(node, node + dice);
                  //cout << "node " << node << "  " << node + dice << endl;
                }
        }
    }

    ll ans = g.bfs();

    cout << ans << "\n";

	}

}
