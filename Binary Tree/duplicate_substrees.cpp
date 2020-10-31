// 652. Find Duplicate Subtrees

class Solution {

// serialized string and nodes whose subtee serialise into
// that string

unordered_map<string, vector<TreeNode *> > mapp;

    string serialize(TreeNode * root){

        if(!root)
            return "";

        string ser = to_string(root->val) + "(" + serialize(root->left) +  ")" + "(" + serialize(root->right) + ")";

        mapp[ser].push_back(root);
        return ser;
    }


public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        vector<TreeNode* > duplicates;

        if(!root) return duplicates;

        serialize(root);
        for(auto i: mapp){

            if(i.second.size() > 1){
                duplicates.push_back(i.second[0]);
            }
        }

        return duplicates;
    }
};
