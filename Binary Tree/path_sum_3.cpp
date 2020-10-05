// 437. Path Sum III

class Solution {
unordered_map<int, int> sums;
int total_path = 0;

void traversal(TreeNode * root, int sum, int path_sum ){

    if(!root)
        return;

    path_sum += root->val;

    if(sums.find(path_sum - sum) != sums.end()){
        total_path += sums[path_sum - sum];
        cout << root->val;
    }

    sums[path_sum]++;
    traversal(root->left, sum, path_sum);
    traversal(root->right, sum, path_sum);
    sums[path_sum]--;
    return;
}



public:
    int pathSum(TreeNode* root, int sum) {
         if(!root)
             return 0;

         sums[0]++;
         traversal(root, sum, 0);
         return total_path;
    }
};
