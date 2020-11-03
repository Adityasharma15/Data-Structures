// 31. Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // we move from the left of array and find the first
        // element which is lesser than the previous one.
        int n = nums.size(), i;
        for(i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1])
                break;
        }

        // if sorted in non-increasing order, we can not find
        // next permutation
        if(i == -1){
            sort(nums.begin(), nums.end());
            return;
        }

        // sort the array in non-decreasing order after ith
        // position, because we want the very next permutation
        sort(nums.begin()+(i+1), nums.end());

        // find the very next greater number from nums[i] &
        // swap it with that
        int j = i+1;
        while(j<n && nums[j]<=nums[i]){
            j++;
        }

        swap(nums[i], nums[j]);
        return;
    }
};
