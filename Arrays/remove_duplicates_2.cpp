// 80. Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int index = 0;

        // keep adding those who have not been included twice already
        for(auto num: nums){

            if(index<2 || num>nums[index-2])
                nums[index++] = num;
        }

        return index;

    }
};
