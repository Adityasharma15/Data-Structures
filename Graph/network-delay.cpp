// 743. Network Delay Time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {

        if(!times.size() || N == 1)
            return -1;

        // if(times.size() == 1)
        // {
        //     return times[0][2];
        // }

        // declaring a weighted directed graph
        vector<vector< pair<int, int> > > graph(N+1);

        // initialising the graph
        for(auto i: times)
        {
            graph[i[0]].push_back({i[1], i[2]});
        }

        // min heap
        priority_queue< pair<int, int>, vector<pair<int, int>> ,greater<pair<int, int>> > pq;

        pq.push({0,K});
        int max_dist = 0;
        unordered_set< int> nodes;
        nodes.insert(K);

        // Dijkstra's
        while(!pq.empty())
        {
           pair<int, int> node = pq.top();
           nodes.insert(node.second);
           max_dist = max(max_dist, node.first);
           pq.pop();

           if(nodes.size() == N)
               return max_dist;

           for(auto x: graph[node.second])
           {
               pq.push({node.first + x.second, x.first});
           }
        }

        return -1;
    }
};
