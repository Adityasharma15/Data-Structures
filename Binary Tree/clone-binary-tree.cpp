// Clone a Binary Tree

Node* cloneTree(Node* tree)
{
    if(tree == NULL)
        return NULL;

    int val = tree->data;
    Node * clone = new Node(val);

    clone->left = cloneTree(tree->left);
    clone->right = cloneTree(tree->right);

    return clone;
}
