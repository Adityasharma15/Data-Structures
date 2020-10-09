// 111. Minimum Depth of Binary Tree

class Solution {
public:
    int minDepth(TreeNode* root) {

        if(!root)
            return 0;

        if(!root->left)
            return 1 + minDepth(root->right);

        if(!root->right)
            return 1 + minDepth(root->left);

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
