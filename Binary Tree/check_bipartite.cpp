// 785. Is Graph Bipartite?

class Solution {
// graph is bipartite if we can color it using
// only 2 colors, we will do bfs and try to color adjacent
// nodes differently but overall only 2 colors needs to be
// used, if we are able to do so, our answer is yes.

public:
    bool isBipartite(vector<vector<int>>& graph) {

        // 0 means uncolored, can also be used to symbolise
        // unvisited
        // 1 means color1 & -1 means color2

        int v = graph.size();
        vector<int> color(v+1, 0);

        if(!v) return true;

        queue<int> que;

        for(int i = 0; i<v; i++){

        // if already colored
        if(color[i]) continue;

        // create a queue and enter any element to initialise
        // bfs & mark it with any color, general start for bfs.
        color[i] = 1;
        que.push(i);

        while(!que.empty()){

            int curr_node = que.front();
            que.pop();

            // visit all the neighbours of current node
            // if they are marked with the same color already,
            // return false, or mark it with color diff from current
            // node, if already colored with diff color, skip.
            for(auto neighbour: graph[curr_node]){

                if(color[neighbour] == color[curr_node])
                    return false;

                if(color[neighbour] == 0){
                   color[neighbour] = (-1)*color[curr_node];
                   que.push(neighbour);
                }
            }
        }
        }
        // if we were able to color the graph using only
        // 2 colors, the graph is bipartite
        return true;
    }
};
