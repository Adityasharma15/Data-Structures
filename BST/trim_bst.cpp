// 669. Trim a Binary Search Tree

class Solution {

public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if(!root)
            return NULL;

        // if value of current node is less than low, then we will
        // only go through the right subtree
        if(root->val < low)
            return trimBST(root->right, low, high);

        // if value of current node is greater than high, then we
        // only go through the left subtree
        if(root->val > high)
            return trimBST(root->left, low, high);

        // if we've reached here, then this root has to be added
        // now traverse to both the sides of this root and see
        // if there are some more good nodes anywhere, directly
        // appending them accoring to the left or right side.
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
