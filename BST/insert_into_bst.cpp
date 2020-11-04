// 701. Insert into a Binary Search Tree

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(!root){
            TreeNode * node = new TreeNode(val);
            return node;
        }

        if(root->val > val){
            if(root->left){
                insertIntoBST(root->left, val);
            }  else{
                TreeNode * node = new TreeNode(val);
                root->left = node;
            }

        } else{

            if(root->right){
                insertIntoBST(root->right, val);
            } else {
                TreeNode * node = new TreeNode(val);
                root->right = node;
            }
        }

        return root;
    }
};
