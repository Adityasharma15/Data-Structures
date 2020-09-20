// 230. Kth Smallest Element in a BST

class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {                                                                       return find(root, k);
    }

    int find(TreeNode * root, int &k)
    {

        if(!root)
            return -1;

        int value = find(root->left, k);

        if(!k)
            return value;

        if(!--k)
            return root->val;

        return find(root->right, k);
    }
};
