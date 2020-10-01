// 106. Construct Binary Tree from Inorder and Postorder Traversal

class Solution {

unordered_map<int , int > nodes_inorder;

    TreeNode* constructTree(vector<int> &inorder, int start_i, int end_i,  vector<int> & postorder, int start_p, int end_p)
    {
        if(start_i > end_i || start_p > end_p || end_p < 0)
            return NULL;


        int root = postorder[end_p];
        TreeNode * temp_node = new TreeNode(root);

        // location of root node in inorder vector
        int pos = nodes_inorder[root];
        int x = start_i;

        cout << x << " " << root << "\n";

        // the diff bw the start of inorder vector and the pos of root in inorder has
        // to be taken care of in the postorder as well. The elements should be                     // corresponding.


        // call to left subtree;
        temp_node->left = constructTree(inorder, start_i, pos-1, postorder, start_p, start_p + (pos - x)-1);

        // call to right subtree
        temp_node->right = constructTree(inorder, pos+1, end_i, postorder, start_p + (pos-x), end_p - 1);

        return temp_node;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    for(int i = 0; i<inorder.size(); i++){
        nodes_inorder[inorder[i]] = i;
    }

    TreeNode * root = constructTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() -1 );

        return root;
    }
};
