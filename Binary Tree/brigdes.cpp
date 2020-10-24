// 1192. Critical Connections in a Network

class Solution {

int timer = 0;
vector<vector<int>> graph, articulation_points;
vector<bool> visited;

// in time indicates the time this node was discovered
vector<int> in_time;

// low time indicates the time of lowest node this node
// can reach, not considering the edge of the dfs tree/
// the node connecting to its parent
vector<int> low_time;

   void dfs(int node, int parent){

       visited[node] = true;

       // we suppose there is no back edge, so this will be the
       // in time & low time of the nodes
       low_time[node] = in_time[node] = timer++;

       for(auto child: graph[node]){

           // low time can never be updated for edge connecting a node to
           // its parent, because we look to destroy this edge & find if              // it will increase the no of connected components
           if(child == parent) continue;

           // presence of a back edge
           if(visited[child]){

               // we check condition for min because its not necessary
               // that this child is part of ancestor, could be part
               // of descendant
               low_time[node] = min(low_time[node], in_time[child]);

           } else{

               dfs(child, node);

               // if its child has connection to ancestor, so its
               // low time should also be updated
               low_time[node] = min(low_time[node], low_time[child]);

               if(low_time[child]>in_time[node])
                   articulation_points.push_back(vector<int>{child, node});
           }
       }
       return;
   }



public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        graph.resize(n);
        visited.resize(n, false);
        in_time.resize(n, 0);
        low_time.resize(n, 0);

        for(int i = 0; i<connections.size(); i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }

        for(int i =0; i<n; i++){
            dfs(i, -1);
        }

        return articulation_points;
    }

       // *if we needed articulation points*
       // for the root node, we will check whether it is articulation point
       // based on the no. of subtrees it has, if it has more than one
       // subtree, it is an articulation point, because there will be no
       // in time less than the in time of root node
};
