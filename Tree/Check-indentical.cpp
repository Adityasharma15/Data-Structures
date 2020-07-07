// Check whether two trees are identical

bool isIdentical(Node *r1, Node *r2)
{

    if(r1==NULL && r2==NULL)
        return true;

    if(r1!=NULL && r2!=NULL)
    {
        if(r1->data != r2->data)
            return false;

        return (isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
    }

    return false;
}
