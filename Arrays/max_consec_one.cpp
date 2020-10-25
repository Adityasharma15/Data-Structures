// 485. Max Consecutive Ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count = 0, max_count = 0;
        for(auto num : nums){

            if(num){
                max_count = max(max_count, ++count);

            } else{
                count = 0;
            }
        }

        return max_count;
    }
};
