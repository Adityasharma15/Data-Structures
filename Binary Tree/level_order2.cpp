// 102. Binary Tree Level Order Traversal

class Solution {
// iterative solution, using queue and NULL as delimeter

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > levelOrderNodes;
        vector<int> currLevelNodes;
        queue<TreeNode * > qu;
        qu.push(root);

        if(!root)
            return levelOrderNodes;

        // NULL is a delimeter which marks the ending of
        // current level
        qu.push(NULL);
        while(!qu.empty()){

            TreeNode * curr_node = qu.front();
            qu.pop();

            if(curr_node == NULL){
                levelOrderNodes.push_back(currLevelNodes);

                // otherwise it will keep adding NULL always
                if(qu.size()) qu.push(NULL);
                currLevelNodes.clear();

            } else{
                currLevelNodes.push_back(curr_node->val);
                if(curr_node->left) qu.push(curr_node->left);
                if(curr_node->right) qu.push(curr_node->right);
            }
        }

        return levelOrderNodes;
    }
};
