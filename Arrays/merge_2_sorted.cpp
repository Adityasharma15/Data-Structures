// 88. Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // ptr points to the very end of first arrya
        // where the maximum element will be present.
        int i = m-1, j = n-1, ptr = m+n;

        // keep adding max of two from last at
        // the end of first array untill one is empty
        while(j>=0 && i>=0){

            if(nums1[i]<nums2[j])
                nums1[--ptr] = nums2[j--];

            else
                nums1[--ptr] = nums1[i--];
        }

        // it is sure that either of two must be
        // empty, so just fill the other one
        // at the end of the first array.

        while(i>=0){
            nums1[--ptr] = nums1[i--];
        }

        while(j>=0){
            nums1[--ptr] = nums2[j--];
        }

        return;
    }
};
