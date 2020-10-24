// 199. Binary Tree Right Side View

class Solution {

        void dfs(TreeNode * node, int level, vector<int>& right_view){

            if(!node) return;

            if(level > right_view.size())
                right_view.push_back(node->val);

            dfs(node->right, level+1, right_view);
            dfs(node->left, level+1, right_view);
            return;
        }

public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> right_view;
        dfs(root, 1, right_view);

        return right_view;
    }
};
