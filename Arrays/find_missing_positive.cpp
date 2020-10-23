// 41. First Missing Positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // The array size will be bw 0 & 300, so
        // the answer will be bw 1 & 301.
        // so we can use a bool hash till 301 to
        // keep visited numbers.
        vector<bool> positive_numbers(302, false);
        for(auto num: nums){
            if(num>0 && num<302){
                positive_numbers[num] = true;
            }
        }

        for(int i = 1; i<302; i++){
            if(!positive_numbers[i])
                return i;
        }

        // base case
        return 1;
    }
};
