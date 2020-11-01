// 987. Vertical Order Traversal of a Binary Tree

class Solution {

// we need to store nodes columnwise and then levelwise, but nodes
// on same level are stored in non-decreasing fashion

public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, set<int>>> mapp;
    vector<vector <int> > vertical_nodes;

    if(!root)
        return vertical_nodes;

    queue<pair<TreeNode *,pair<int, int>>> bfs;
    bfs.push({root, {0,0}});

    while(!bfs.empty()){

        TreeNode * node = bfs.front().first;
        int level = bfs.front().second.first;
        int dist = bfs.front().second.second;
        bfs.pop();

        mapp[dist][level].insert(node->val);
        if(node->left) bfs.push({node->left, {level+1, dist-1}});
        if(node->right) bfs.push({node->right, {level+1, dist+1}});
    }


    for(auto dist : mapp){

        vector<int> column;
        for(auto level : dist.second){
            column.insert(column.end(), level.second.begin(), level.second.end());
        }

        vertical_nodes.push_back(column);
    }
     return vertical_nodes;
    }
};
