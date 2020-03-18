#include<bits/stdc++.h>
using namespace std;

class Graph
{
  int V:
  list<int> adjlist;

  Graph(int v)
  {
    V = v;
    adjlist = new list<int>;
  }

  void add(int a, int b)
  {
    adjlist[a].push_back(b);
  }

  int temp;

  void DFS(int start, bool * visited)
  {
    visited[start] = true;
    cout << start << " ";

    for(auto i: adjlist[start])
    {
      if(!visited[i])
        DFS(i);
    }

  }
};

int main()
{
    Graph g(4);
    g.add(1,3);
    g.add(2,1);

    bool * visited[4];
    memset(visited, false, sizeof(visited));

    DFS(0, visited);

}
