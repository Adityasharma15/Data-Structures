// 98. Validate Binary Search Tree

bool constraints(TreeNode * node, TreeNode * min, TreeNode * max){
        if(!node)
            return true;

        if(min && node->val <= min->val)
            return false;

        if(max && node->val >= max->val)
            return false;

        return constraints(node->left, min, node) &&
    constraints(node->right, node, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return constraints(root, NULL, NULL);
    }
};
