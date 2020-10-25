26. Remove Duplicates from Sorted Array

class Solution {
// we have to keep a subarray of unique elements
// this makes it a two pointer approach

public:
    int removeDuplicates(vector<int>& nums) {

        // if only 1 element or no element
        if(nums.size() < 2)
            return nums.size();

        // pos points to the last element of the
        // subarray with unique elements
        int pos = 0;
        for(int i = 1; i<nums.size(); i++){

            // we found another unique element, add this
            // to our subarray of unique elements
            if(nums[i]>nums[pos])
                swap(nums[++pos], nums[i]);
        }

        return pos+1;
    }
};
