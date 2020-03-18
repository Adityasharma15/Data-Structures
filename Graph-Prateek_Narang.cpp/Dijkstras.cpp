#include<bits/stdc++.h>
using namespace std;

class Graph
{
  unordered_map<int , list<pair<int, int>>> mapp;

public:
  void add(int u, int v, int dist)
  {
    mapp[u].push_back(make_pair(v,dist));
    mapp[v].push_back(make_pair(u,dist));
  }

  void print()
  {
    for(auto i: mapp)
    {
      cout << i.first << "->";

      for(auto j: i.second)
        {
          cout << j.first << "," << j.second <<" & ";
        }
        cout << endl;
    }
  }


  void Dijkstra(int start)
  {

    unordered_map<int ,int > dist;

    for(auto i: mapp)
      dist[i.first] = INT_MAX;

    set<pair<int,int>> s;

    s.insert(make_pair(0, start));
    dist[start] = 0;

    while(!s.empty())
    {
      auto p = *(s.begin());
      int node = p.second;
      int nodedist = p.first;

      s.erase(s.begin());

      for(auto q: mapp[node])
      {
        if((nodedist + q.second) < dist[q.first])
        {
        auto find =  s.find(make_pair(dist[q.first], q.first));

        if(find!=s.end())
           s.erase(find);

        dist[q.first] = (nodedist + q.second);

        s.insert(make_pair((nodedist +  q.second), q.first));

        //cout << " inserting  " << nodedist +  q.second << "  " << q.first << endl;

        }
      }

    }

    for(auto i: dist)
      cout << i.first << " " << i.second << endl;

  }

};


int main()
{
  Graph g;

    // g.add(0,1,0);
    // g.add(0,2,3);
    // g.add(1,2,0);
    // g.add(2,3,1);
    // g.add(0,3,6);

  g.add(1,3,4);
  g.add(1,2,1);
  g.add(3,4,8);
  g.add(3,2,2);
  g.add(4,5,3);
  g.add(5,6,2);
  g.add(6,2,1);

  //g.print();
  g.Dijkstra(1);
}
