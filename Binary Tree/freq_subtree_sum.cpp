// 508. Most Frequent Subtree Sum

class Solution {

unordered_map<int, int> sum_freq;
int findsum(TreeNode *root){

    if(!root)
        return 0;

    int leftsum = findsum(root->left);
    int rightsum = findsum(root->right);

    int total = leftsum + rightsum + root->val;
    sum_freq[total]++;
    return total;
}

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {

        vector<int> sum;
        if(!root)
            return sum;

        findsum(root);
        int max_freq = 1;
        for(auto freq: sum_freq){
            max_freq = max(max_freq, freq.second);
        }

        for(auto freq: sum_freq){
            if(freq.second == max_freq)
                sum.push_back(freq.first);
        }

        return sum;
    }
};
