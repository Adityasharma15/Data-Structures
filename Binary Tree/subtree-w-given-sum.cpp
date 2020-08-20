// Count Number of SubTrees having given Sum

int summ(Node * root)
{
    if(root == NULL)
        return 0;

    return summ(root->left) +  summ(root->right) + root->data;
}

int countSubtreesWithSumX(Node* root, int X)
{
	if(root == NULL)
	    return 0;

	int sum = root->data + summ(root->left) + summ(root->right);

    int left = countSubtreesWithSumX(root->left, X);
    int right = countSubtreesWithSumX(root->right, X);

    if(sum == X)
        return left + right + 1;

    else
        return left + right;
}
