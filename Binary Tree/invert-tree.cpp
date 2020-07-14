 // Invert Binary Tree
 // https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
 // https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL)
            return root;

        TreeNode* left = NULL;
        TreeNode* right = NULL;

        if(root->left!=NULL)
            left = root->left;

        if(root->right!=NULL)
            right = root->right;

        root->left = right;
        root->right = left;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
