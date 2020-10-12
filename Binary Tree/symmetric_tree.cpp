// 101. Symmetric Tree

class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if(!root) return true;
        return symmetryUtil(root->left, root->right);
    }

    bool symmetryUtil(TreeNode * root1, TreeNode * root2){

        if(!root1 && !root2){
            return true;
        } if(!root1 || !root2)
            return false;

        if(root1->val != root2->val){
            return false;
        }

        return symmetryUtil(root1->left, root2->right) && symmetryUtil(root1->right, root2->left);
    }
};
