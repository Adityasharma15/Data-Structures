// 503. Next Greater Element II

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        stack<int> stck;
        vector<int> next_greater(n, -1);

        for(int i = 0; i<(2*n); i++){

            while(!stck.empty() && nums[stck.top()%n]<nums[i%n]){
                next_greater[stck.top()] = nums[i%n];
                stck.pop();
            }
                stck.push(i%n);
        }

        return next_greater;
    }
};
