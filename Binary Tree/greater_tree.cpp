// 538. Convert BST to Greater Tree

class Solution {

// this is the highlight of this problem, we can see the need
// of keeping the largest value optained in a subtree in the left
// for the value of root node.
int curr_overall_sum = 0;

    void add_greater(TreeNode * root){

        if(!root)
            return;

        // directly call for right child as it will not be impacted
        // by the change in value of the current node
        if(root->right)
            add_greater(root->right);

        // change the value of the root acc to the high value of
        // right subtree
        root->val += curr_overall_sum;
        curr_overall_sum = root->val;

        if(root->left)
          add_greater(root->left);

        return;
    }

public:
    TreeNode* convertBST(TreeNode* root) {

        if(root)
         add_greater(root);

        return root;
    }
};
