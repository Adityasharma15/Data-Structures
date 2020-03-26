// Just a function

Node* LCA(Node *root, int n1, int n2)
{

   if(root->data > max(n1,n2))
    LCA(root->left, n1, n2);

    else if(root->data <  min(n1,n2))
        LCA(root->right, n1 ,n2);

    else
        return root;


}
