// Maximum Path Sum between 2 Leaf Nodes

pair<int,int> maxPathSumUtil(Node *root)
{
    if(root == NULL)
        return {0,0};

    pair<int,int> p1 = maxPathSumUtil(root->left);
    pair<int,int> p2 = maxPathSumUtil(root->right);

    //first part is sum from that point to lower part
    // second part is max value

    if(root->left == NULL && root->right == NULL)
        return{ root->data, INT_MIN};

    if(root->left == NULL)
        return { (p2.first + root->data), INT_MIN};

    if(root->right == NULL)
        return { (p1.first + root->data), INT_MIN};

return {(max(p1.first, p2.first) + root->data),max( max(p1.second, p2.second) ,(p1.first + p2.first + root->data))};
}


int maxPathSum(Node* root)
{
    pair<int,int> p = maxPathSumUtil(root);
    return p.second;
}
