// 530. Minimum Absolute Difference in BST

class Solution {

int min_diff = INT_MAX;
TreeNode * previous = NULL;

    void inorder(TreeNode * root){

        if(!root)
            return;

        inorder(root->left);

        if(previous)
            min_diff = min(min_diff, root->val-previous->val);

         previous = root;

         inorder(root->right);
         return;
    }

public:
    int getMinimumDifference(TreeNode* root) {
            inorder(root);
            return min_diff;
    }
};
