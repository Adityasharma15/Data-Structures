// 563. Binary Tree Tilt

class Solution {
int tilt = 0;

public:
    int findTilt(TreeNode* root) {
        tiltfind(root);
        return tilt;
    }

    int tiltfind(TreeNode * root){

        if(!root)
            return 0;

        int left = tiltfind(root->left);
        int right = tiltfind(root->right);

        tilt += abs(left - right);

        return left + right + root->val;
    }

};
