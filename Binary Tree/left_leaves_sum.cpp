// 404. Sum of Left Leaves

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        if(!root)
            return 0;

        // if root has left node and that left node is leaf node
        // count that in sum and recurr for right part of root
        if(root->left && !root->left->left && !root->left->right)
            return root->left->val + sumOfLeftLeaves(root->right);

        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
