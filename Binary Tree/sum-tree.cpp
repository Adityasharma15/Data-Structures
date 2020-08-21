// Transform to Sum Tree

int add(Node * node)
{
    if(!node)
        return 0;

    int data = node->data;

    node->data = add(node->left) + add(node->right);
    return node->data + data;
}

// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
void toSumTree(Node *node)
{
    if(!node)
        return;

    node->data = add(node->left) + add(node->right);
    return;
}
