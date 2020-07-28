// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int end = (nums.size()-1);
        int start = 0, curr = 0;

        while(curr <= end)
        {
            cout << nums[curr] <<" ";

            if(nums[curr] == 0)
            {
                swap(nums[curr++], nums[start++]);
            }

            else if(nums[curr] == 2)
            {
                swap(nums[curr], nums[end--]);
            }

            else
            curr++;

        }

    }
};
