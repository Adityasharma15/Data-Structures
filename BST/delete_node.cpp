// 450. Delete Node in a BST

class Solution {

public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(!root)
            return NULL;

        if(root->val > key)
            root->left = deleteNode(root->left, key);

        else if(root->val < key)
            root->right = deleteNode(root->right, key);

        // found key
        else{

           // 0 child
           if(!root->left && !root->right){
               delete(root);
               return NULL;
           }

            // 1 child
            if(!root->left || !root->right){
                TreeNode *child = root->left? root->left : root->right;
                delete(root);
                return child;
            }

            // 2 child
            TreeNode * left = root->left;
            TreeNode * right = root->right;
            root = root->left;

            while(root->right){
                root = root->right;
            }

            root->right = right;
            return left;
        }

        return root;
    }
};
