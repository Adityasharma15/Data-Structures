// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

pair<int,int> maxPathSumUtil(TreeNode *root)
{
    if(root == NULL)
        return {0,INT_MIN};

    pair<int,int> p1 = maxPathSumUtil(root->left);
    pair<int,int> p2 = maxPathSumUtil(root->right);

    //first part is continuos sum from that point to lower part
    // second part is answer

    if(root->left == NULL && root->right == NULL)
        return{ root->val, root->val};

    // max amongst right substree or left subtree or continuos left & right(including the parent node as well)
    int temp = max( max(p1.second, p2.second),(p1.first + p2.first + root->val));

    // max amongst right subtree + root node or left subtree + root node
    int temp2 = max( p1.first + root->val, p2.first + root->val );

    // max amongst these
    int temp3 = max(temp, temp2);

    // either only the current node is the answer
    temp3 = max(temp3, root->val);

    // for continuos sum, there are options to chose left + node or right + node, and also only node.
    int temp4 = max(max(p1.first + root->val, p2.first+root->val),root->val);

      return {temp4, temp3};
}
    int maxPathSum(TreeNode* root)
    {
        pair<int,int> p = maxPathSumUtil(root);
        return p.second;
    }

};
