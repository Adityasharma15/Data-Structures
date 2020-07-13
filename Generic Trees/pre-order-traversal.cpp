 // N-ary Tree Preorder Traversal
 // https://leetcode.com/problems/n-ary-tree-preorder-traversal/

class Solution {
public:
    void preorderUtil(Node * root, vector<int> &ans)
    {
        if(root == NULL)
            return;

        ans.push_back(root->val);
        for(auto i: root->children)
        {
            preorderUtil(i, ans);
        }
    }


public:
    vector<int> preorder(Node* root) {
        vector<int> ans;

        if(root == NULL)
            return ans;

        preorderUtil(root, ans);
        return ans;
    }
};
