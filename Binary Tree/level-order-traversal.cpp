// this is a function to implement level order traversal


void levelOrder(Node* node)
{
  if(node == NULL)
    return;


  queue<struct Node *> qu;

  qu.push(node);


  while(qu.empty()!=true)
  {


    int sizee = qu.size();

    while(sizee--)
    {

    Node * temp = qu.front();

    cout << temp->data << " ";

    qu.pop();

    if(temp->left!=NULL)
        qu.push(temp->left);

    if(temp->right!=NULL)
        qu.push(temp->right);

    }

    cout << "$" << " ";
  }




}
