// 1. Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mapp;
        vector<int> ans;

        for(int i = 0; i<nums.size(); i++){

            if(mapp.find(target - nums[i])!= mapp.end()){
                ans.push_back(i);
                ans.push_back(mapp[target - nums[i]]);
                break;
            }

            mapp[nums[i]] = i;
        }

        return ans;
    }
};
