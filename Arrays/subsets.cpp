// 78. Subsets

class Solution {
vector<vector<int>> total_subsets;

    void add_subsets(vector<int> &nums, vector<int>subset, int begin){

        total_subsets.push_back(subset);
        for(int i = begin; i<nums.size(); i++){

            subset.push_back(nums[i]);
            add_subsets(nums, subset, i+1);
            subset.pop_back();
        }
        return;
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> subset;
            add_subsets(nums, subset, 0);
            return total_subsets;
    }
};
