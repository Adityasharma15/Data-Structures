// 99. Recover Binary Search Tree


// There are two nodes not in their places, so one will be larger than the other,
// let's say a is the larger node and b is the smaller node and both of them needs
// to be swapped in order to correct the binary search tree, so now, surely a is
// taking the place of a smaller number(b), so a will come earlier in the inorder
// traversal, so whenever we find a pair not following the non dec order in the
// inorder traversal, the first element is always the prev node. And to handle case
// when only the first occuring problematic pair needs to be sorted, we assign
// second to the current node as well, but if we a pair like this again, we will
// simply assign second to the current node as it is taking a place of a bigger node




class Solution {
public:

// first points to first misplaced node and second points
// to the second one, prev points to the prev node in the
// inorder traversal.
TreeNode * first = NULL;
TreeNode * second = NULL;
TreeNode * prev = new TreeNode(INT_MIN);

    void recoverTree(TreeNode* root)
    {
        if(!root)
            return;

        find(root);
        swap(first->val, second->val);
    }

    void find(TreeNode * root)
    {
        if(!root)
            return;

        find(root->left);

        // in case we find inorder is not in non dec order, we assign first
        // as prev, we have talked about in brief earlier.
        if(prev->val > root->val && first ==NULL)
            first = prev;


        // we have not used else if here to avoid corner cases, whenever some
        // pair not following the non dec order occurs, we assign first and second
        // pointers to the nodes respectively, to handle the case where only both
        // of them are to be swapped. If we find some other node not following the
        // order, we will assign second to that node as this if condition will
        // satisfy for that as well.
        if(prev->val > root->val && first !=NULL)
            second = root;

        prev = root;

        find(root->right);

        return;
    }

};
