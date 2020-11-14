// Clone a Binary Tree

Node *copyLeftRight(Node *original, unordered_map<Node*, Node*> &orig_copy){

    if(!original)
     return NULL;

    Node *copy = new Node(original->data);
    orig_copy[original] = copy;
    copy->left = copyLeftRight(original->left, orig_copy);
    copy->right = copyLeftRight(original->right, orig_copy);
    return copy;
}


void copyRandom(Node *original, Node*copy, unordered_map<Node*, Node*> &orig_copy){

    if(!original)
    return;

    copy->random = orig_copy[original->random];
    copyRandom(original->left, copy->left, orig_copy);
    copyRandom(original->right, copy->right, orig_copy);
    return;
}

Node* cloneTree(Node* tree)
{
    if(tree == NULL)
        return NULL;

    // marks orig to duplicate
    unordered_map<Node*, Node*> orig_copy;

    // first copy left & right
    Node *copy_root = copyLeftRight(tree, orig_copy);

    // then assign random
    copyRandom(tree, copy_root, orig_copy);

    return copy_root;
}
