// 236. Lowest Common Ancestor of a Binary Tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // if we are at NULL , return NULL
        // if we are at either p or q, return that
        if(!root || root == p || root == q)
            return root;

        // calling out for left & right subtrees
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right = lowestCommonAncestor(root->right, p , q);

        // in case any one of left or right is NULL, return the other
        // one. If we have found both, then return the node.

        return !right ? left : !left ? right : root;

    }
};
