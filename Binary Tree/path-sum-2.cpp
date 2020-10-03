// 113. Path Sum II

class Solution {

    // the idea is using backtracking
    // the 2d vector containing all paths;
    vector<vector<int> > paths

    // we will traverse through nodes
    void traversal(TreeNode * root, int sum, vector<int> path)
    {
        if(!root)
            return;

        //if it is a leaf node, check if it can form the sum
        // then add it. We don't check for null root as if a leaf
        // root contributes to the desired path, then it will call,
        // its left and right and thus the path gets added twice
        // so we check on the root leaf itself
        if(!root->left && !root->right){
            if((sum - root->val) == 0){
                path.push_back(root->val);
                paths.push_back(path);
            }

            return;
        }

        // add this node to the vector going on, if it contributes
        // to the desired path, it will be added.
        path.push_back(root->val);
        traversal(root->left, sum - root->val, path);
        traversal(root->right, sum - root->val, path);
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        if(!root)
            return paths;

        vector<int> path;
        traversal(root, sum, path);
        return paths;
    }
};
