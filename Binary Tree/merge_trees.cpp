// Merge Two Binary Trees

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

        // if any one or both are NULL
        if(!t1 || !t2)
            return t1 ? t1 : t2 ? t2 : NULL;

        TreeNode * node = new TreeNode(t1->val + t2->val);
        node->left = mergeTrees(t1->left, t2->left);
        node->right = mergeTrees(t1->right, t2->right);
        return node;
    }
};
