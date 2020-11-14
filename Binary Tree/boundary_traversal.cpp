// Boundary Traversal of binary tree

void printLeft(Node *root, vector<int> &boundary_nodes){

    if(!root)
    return;

    if(root->left){
        boundary_nodes.push_back(root->data);
        printLeft(root->left, boundary_nodes);

    }else if(root->right){
        boundary_nodes.push_back(root->data);
        printLeft(root->right, boundary_nodes);
    }

    // if both left and right are not present, then this is a leaf node
    // and will be added by printLeaves

    return;
}


void printLeaves(Node *root, vector<int> &boundary_nodes){

    if(!root)
      return;

  printLeaves(root->left, boundary_nodes);

   if(!root->left && !root->right){
       boundary_nodes.push_back(root->data);
   }

   printLeaves(root->right, boundary_nodes);
   return;
}

void printRight(Node *root, vector<int> &boundary_nodes){

    if(!root)
    return;

    if(root->right){
        // to ensure bottom up traversal, first call the right subtree
        printRight(root->right, boundary_nodes);
        boundary_nodes.push_back(root->data);
    }

    else if(root->left){
        printRight(root->left, boundary_nodes);
        boundary_nodes.push_back(root->data);
    }

    return;
}

vector <int> printBoundary(Node *root)
{
    // put root manually to avoid duplicacy
    vector<int> boundary_nodes{root->data};
    printLeft(root->left, boundary_nodes);
    printLeaves(root->left, boundary_nodes);
    printLeaves(root->right, boundary_nodes);
    printRight(root->right, boundary_nodes);
    return boundary_nodes;
}
