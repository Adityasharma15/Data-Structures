// 95. Unique Binary Search Trees II

class Solution {
// Divide and conquer technique

public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
            return vector<TreeNode*>() ;

        return constructTrees(1, n);
    }

    vector<TreeNode *> constructTrees(int left, int right){

        vector<TreeNode *> TreePermutation;

        // if no permutations of tree possible, return NULL
        if(left>right){
            TreePermutation.push_back(NULL);
            return TreePermutation;
        }

        // make everyone root once, and find permutations around this
        // root for left & right subtree
        for(int root = left; root<=right; root++){

            vector<TreeNode*> leftSubtree = constructTrees(left, root-1);
            vector<TreeNode*> rightSubtree = constructTrees(root+1, right);

            // for every permutation of left subtree, combine it with some
            // permutation of right subtree.
            for(auto l: leftSubtree){
                for(auto r : rightSubtree){

                    TreeNode *node = new TreeNode(root);
                    node->left = l;
                    node->right = r;
                    TreePermutation.push_back(node);
                }
            }
        }

        return TreePermutation;
    }


};
