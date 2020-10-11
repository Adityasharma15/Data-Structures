// 543. Diameter of Binary Tree

class Solution {
int max_diameter = 0;

    int findDiameter(TreeNode * root){
        if(!root)
            return 0;

        int left_diameter = findDiameter(root->left);
        int right_diameter = findDiameter(root->right);

        // here we calculate the overall max diameter which may or may not
        // include the nodes above this root node, we check if a u shape
        // path from left of this node going right of this node
        // makes the longest path or not.
        max_diameter = max(max_diameter, left_diameter + right_diameter);

        // here we simply return the longest possible path including the
        // parents of this node, so it includes itself with the longest path
        // to either to its left or its right and gives the other end of
        // this path to its parent to decide for this.
        return max(left_diameter, right_diameter) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
            findDiameter(root);
            return max_diameter;
    }


};
