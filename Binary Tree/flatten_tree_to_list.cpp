// 114. Flatten Binary Tree to Linked List

class Solution {
public:
    void flatten(TreeNode* root) {

        // we are changing left to right, so store the initial
        // right, and then change right to initial left

        if(!root)
            return;

        TreeNode * right_initial = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode * curr = root;

        // traversing till the last right, and then adding the
        // initial right to its right position
        while(root->right){
            root = root->right;
        }

        root->right = right_initial;

        // recurring to the next node as we are done for this node
        flatten(curr->right);
        return;
    }
};
