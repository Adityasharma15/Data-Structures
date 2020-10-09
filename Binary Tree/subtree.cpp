// 572. Subtree of Another Tree

class Solution {

    bool isSame(TreeNode * s, TreeNode * t){

        if(!s && !t)
            return true;

        if(!s || !t)
            return false;

        if(s->val!= t->val)
            return false;

        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }


public:
    bool isSubtree(TreeNode* s, TreeNode* t) {

        // compare root of t with each node of s
        if(isSame(s, t))
            return true;

        if(!s)
            return false;

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
