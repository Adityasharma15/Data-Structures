// 863. All Nodes Distance K in Binary Tree

class Solution {

// we can't perform bfs to all adjacent neighbours of our target node
// because this is a tree, so if we store parents of each node, then
// our problem is solved

vector<int> k_distant;
unordered_map<TreeNode * , TreeNode * > parent;
unordered_set<TreeNode * > visited;

 // assigning parents to each node
 void findparent(TreeNode * root){
     if(!root)
         return;

     if(root->left){
         parent[root->left]= root;
         findparent(root->left);
     }

     if(root->right){
         parent[root->right] = root;
         findparent(root->right);
     }

     return;
 }

 // simple bfs, iterating all nodes and pushing all nodes at distance k
//  into k_distant
 void bfs(TreeNode * root, int distance){

     if(visited.count(root) > 0)
         return;

     visited.insert(root);

     if(distance == 0){
         k_distant.push_back(root->val);
         return;
     }

     if(root->left){
         bfs(root->left, distance -1 );
     }

     if(root->right){
         bfs(root->right, distance - 1);
     }

     if(parent[root]){
         bfs(parent[root], distance - 1);
     }

     return;
 }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

        findparent(root);
        bfs(target, K);
        return k_distant;
    }
};
