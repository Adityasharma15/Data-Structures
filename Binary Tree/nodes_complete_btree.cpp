// 222. Count Complete Tree Nodes

class Solution {
public:
    int countNodes(TreeNode* root) {

        if(!root)
            return 0;


         int leftDepth = 0;
         int rightDepth = 0;

         TreeNode * node = root;

         while(node){
             leftDepth++;
             node = node->left;
         }

         node = root;
         while(node){
             rightDepth++;
             node = node->right;
         }

        // using sum of GP
        if(leftDepth == rightDepth){
            return (1<<leftDepth) - 1;
        }

        else{
            return countNodes(root->right) + countNodes(root->left) + 1;
        }
    }
};
