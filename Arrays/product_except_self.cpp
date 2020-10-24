// 238. Product of Array Except Self

class Solution {

// the first thought is to maintain two arrays prefix product
// and postfix product, and then multiply the prefix product
// before this element and postfix product after this element
// to get answer. But, the same can be done using 2 pointers
// each pointer will keep storing its product into the array.

public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> pwithout_self(n,1);
        int pfrombegin = 1;
        int pfromend = 1;

        for(int i = 0; i<n; i++){
            pwithout_self[i] *= pfrombegin;
            pfrombegin *= nums[i];
            pwithout_self[n-i-1] *= pfromend;
            pfromend *= nums[n-i-1];
        }

        return pwithout_self;
    }
};
