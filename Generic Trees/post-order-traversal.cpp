// N-ary Tree Postorder Traversal
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

class Solution {

    void postorderUtil(Node * root, vector<int> &ans)
    {
        if(root == NULL)
            return;

        for(auto i: root->children)
        {
            postorderUtil(i, ans);
        }
        ans.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> ans;

        if(root == NULL)
            return ans;

        postorderUtil(root, ans);
        return ans;
        }
};
