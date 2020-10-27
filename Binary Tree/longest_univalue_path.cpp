// 687. Longest Univalue Path

class Solution {
// Note : lengths of path is the no of edges in it and not nodes in it

// we will maintain maximum lenght of path found
int max_len = 0;

    int dfs(TreeNode * node){

        if(!node)
            return 0;

        // find values from left node and right node
        int left = node->left ? dfs(node->left) : 0;
        int right = node->right ? dfs(node->right) : 0;

        // if the current node equal to the left or right node, it can
        // include itself in them.
        int result_left = node->left && node->left->val == node->val ? left + 1 : 0;

        int result_right = node->right && node->right->val == node->val ? right + 1 : 0;

        // this is the max length across this node
        max_len = max(max_len, result_left + result_right);

        // we will return the max length of open ended path to the
        // node that called this function, so it can add itself if
        // it likes
        return max(result_left, result_right);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
            dfs(root);
            return max_len;
    }
};
