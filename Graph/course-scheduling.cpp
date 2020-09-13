// 210. Course Schedule II

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector< vector<int> > graph (numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        vector<int> sorted;

        // preparing dag so that we can use topological sort
        // dag = directed acyclic graph
        for(auto course: prerequisites)
        {
            graph[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }

        // applying topological sort
        queue<int> nodes;

        //adding nodes that have indegree 0 or say can come
        //before every other node

        for(int i = 0; i<indegree.size(); i++)
        {
            if(indegree[i] == 0)
                nodes.push(i);
        }

        // keep adding nodes to queuev who have no
        // constraint of coming first left, reduce the indegree
        // of the nodes we visit
        while(!nodes.empty())
        {
            int curr_node = nodes.front();
            sorted.push_back(curr_node);
            nodes.pop();

            for(auto x: graph[curr_node])
            {
               if(--indegree[x] == 0)
                   nodes.push(x);
            }

        }

        // if there is a cycle in the graph, our sorted
        // vector will not have all courses
        return sorted.size() == numCourses ? sorted : vector<int>();

    }
};
