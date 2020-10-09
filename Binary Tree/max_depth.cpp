// 104. Maximum Depth of Binary Tree

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(!root)
            return 0;

        int depth = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        return depth;
    }
};
