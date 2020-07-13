// Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root == NULL)
        {
            vector<vector<int>> tempans(0);
            return tempans;
        }

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int maxi = 0;
        unordered_map<int, vector<int>>mapp;

        while(!q.empty())
        {
           pair<TreeNode *, int> temp = q.front();
           q.pop();
           maxi = max(maxi, temp.second);
           mapp[temp.second].push_back(temp.first->val);

           if(temp.first->left!=NULL)
           {
               q.push({temp.first->left,temp.second+1});
           }

           if(temp.first->right!=NULL)
           {
               q.push({temp.first->right,temp.second+1});
           }


        }

        vector<vector<int>> ans(maxi+1);
        for(auto i:mapp)
        {
            vector<int> v = i.second;
            if(i.first%2!=0)
            {
                reverse(v.begin(), v.end());
            }

            for(auto j:v)
            { ans[i.first].push_back(j);
            }
        }

        return ans;
    }
};
