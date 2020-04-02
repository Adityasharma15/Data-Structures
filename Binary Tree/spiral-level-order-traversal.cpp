void printSpiral(Node *root)
{

    if(root == NULL)
        return;


    stack< struct Node *> s1;
    stack<struct Node * > s2;

    s1.push(root);

    while(!s1.empty() || !s2.empty())
    {

        while(!s1.empty())
        {
            Node * temp = s1.top();

            cout << temp->data << " ";

            s1.pop();



            if(temp->right!=NULL)
                s2.push(temp->right);



            if(temp->left!=NULL)
                s2.push(temp->left);


        }


        while(!s2.empty())
        {
            Node * temp = s2.top();

            cout << temp->data << " ";

            s2.pop();
        


            if(temp->left!=NULL)
                s1.push(temp->left);



            if(temp->right!=NULL)
                s1.push(temp->right);


        }

    }

}
