// 257. Binary Tree Paths

class Solution {
vector<string> paths;
    void traverse(TreeNode * root, string s){

        if(!root)
            return;

        s = s + to_string(root->val) + "->";

        // if leaf node, push into this string
        if(!root->left && !root->right){

            // remove -> from end of the string
            s = s.erase(s.size()-2, 2);
            paths.push_back(s);
            return;
        }

        if(root->left) traverse(root->left, s);
        if(root->right) traverse(root->right, s);
        return;
    }


public:
    vector<string> binaryTreePaths(TreeNode* root) {
        traverse(root, "");
        return paths;
    }
};
