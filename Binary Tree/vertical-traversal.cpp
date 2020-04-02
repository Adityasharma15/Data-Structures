void verticalOrderUtil(Node *root, int hd, map<int , vector<int> > &mapp)
{
    if(root == NULL)    return;

    mapp[hd].push_back(root->data);

    verticalOrderUtil(root->left, hd - 1, mapp);
    verticalOrderUtil(root->right, hd + 1, mapp);

}

void verticalOrder(Node *root)
{
    map<int, vector<int> > mapp;

    verticalOrderUtil(root, 0 , mapp);

    for(auto i:mapp)
    {
        for( auto j: i.second)
        {
            cout << j << " ";
        }
    }

}
