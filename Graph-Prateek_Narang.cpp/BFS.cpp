#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adjlist;

public:
    Graph(int v)
    {
      V = v;
      adjlist = new list<int>[V];
    }

    void add(int v, int u)
    {
      adjlist[v].push_back(u);
      adjlist[u].push_back(v);
    }

    void printAll()
    {
        for(int i = 0; i<V; i++)
        {
          cout << i << "->";

          for(auto j: adjlist[i])
            cout << j << ",";
        }
    }

    void bfs(int start)
    {
        bool visited[V];
        bool parent[V];
        int distance[V];

        memset(parent, -1, sizeof(parent));
        memset(visited, false, sizeof(visited));
        memset(distance, 0, sizeof(distance));

        queue<int> q;

        q.push(start);
        visited[start] = true;
        distance[0] = 0;
        parent[0] = 0;

        int temp;

        while(!q.empty())
        {
          temp = q.front();
          cout << " node: " << temp << " shortest distance: " << distance[temp] << " ";
          q.pop();

          for(auto i: adjlist[temp])
            {
              if(visited[i] == false)
               {
                 q.push(i);
                 visited[i] = true;
                 parent[i] = temp;
                 distance[i] = distance[parent[i]] + 1;
               }
            }


        }

    }

};

int main()
{
  Graph g(4);
  g.add(0,1);
  g.add(1,3);
  g.add(2,3);
  g.add(1,2);

  g.bfs(0);
}
