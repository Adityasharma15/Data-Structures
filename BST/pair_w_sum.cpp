// 653. Two Sum IV - Input is a BST

class Solution {
public:
    bool findTarget(TreeNode* root, int k)
    {
        if(!root)
            return false;

        unordered_set<int> sett;
        return traversal(root, sett, k);
    }

    bool traversal(TreeNode * root, unordered_set<int> & sett, int k)
    {
        if(!root)
            return false;

        if(sett.count(k - (root->val)))
            return true;

        sett.insert(root->val);

        return traversal(root->left, sett, k) || traversal(root->right, sett, k);
    }

    };
