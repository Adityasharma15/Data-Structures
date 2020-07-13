 // N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {


        if(root ==NULL)
        {
            vector<vector<int>> tempans(0);
            return tempans;
        }

        vector<pair<int, int>> temp;
        queue<pair<Node *, int>> q;
        q.push({root,0});
        int maxi = 0;

        while(!q.empty())
        {
            pair<Node *, int> p = q.front();
            q.pop();

            temp.push_back( {p.first->val, p.second} );
            maxi = max(maxi, p.second);

            for(auto i:p.first->children)
            {
                q.push({i, p.second+1});

            }
        }

        vector<vector<int>> ans(maxi+1);



        for(auto i:temp)
        {
            ans[i.second].push_back(i.first);
        }

        return ans;
    }
};
