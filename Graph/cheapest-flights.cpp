// 787. Cheapest Flights Within K Stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        // creating a weighted graph
        vector<vector<pair<int, int>>> graph(n);

        for(auto i: flights)
        {
            graph[i[0]].push_back({i[1], i[2]});
        }

        // creating a min heap or a priority queue
        // having distance, src and nodes left(where we can stop)
        // priority queu will be based upon distance, the node with least distance will
        // come on top
        priority_queue < pair<int, pair<int, int> > , vector < pair <int, pair<int, int> > > , greater<pair<int, pair<int, int> > > > pq;

        pq.push( {0, { src, K} });

        // applying Dijkstra's Algorithm for shortest path from single source
        while(!pq.empty())
        {
          pair<int, pair<int, int> > node = pq.top();
          pq.pop();

          // if current node is destination, return cost uptill now
          if(node.second.first == dst)
            return node.first;

          // if nodes that we can visit is finished, skip this node
          if(node.second.second < 0)
              continue;

          // now iterate over other nodes of the current node - distance will be
          // distance uptill this node + dist from this node to that neighbour node
          // and nodes which we can visit will be on less.
          for(auto i: graph[node.second.first])
          {
            pq.push({(node.first + i.second),{i.first,(node.second.second-1)}});
          }
        }

        return -1;
    }
};
