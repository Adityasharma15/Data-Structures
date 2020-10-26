// 90. Subsets II

class Solution {
vector<vector<int>> subsets;

    void addsubset(vector<int> nums, vector<int> subset, int begin){

        subsets.push_back(subset);
        for(int i = begin; i<nums.size(); i++){

            // if there is special call for a duplicate number only
            // then we will add it, otherwise we will skip it when
            // it occurs while simply traversing the array
            if(i!=begin && nums[i] == nums[i-1])
                continue;

            subset.push_back(nums[i]);
            addsubset(nums, subset, i+1);
            subset.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(), nums.end());
        addsubset(nums, subset, 0);
        return subsets;
    }
};
