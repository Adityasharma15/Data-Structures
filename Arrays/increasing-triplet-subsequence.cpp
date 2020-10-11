// 334. Increasing Triplet Subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int a = INT_MAX, b = INT_MAX;

        for(auto i :nums){

            // if a number comes and a is not assigned yet, or
            // this is smaller than a, lock this for a
            if(i<=a){
                a = i;
            }

            // if a number comes and b is not assigned yet, or
            // this is smaller than b, lock this for b as a is                 // assigned and this no. is greater than a
            else if(i<=b){
                b = i;
            }

            // if both a and b are assigned and this no. is greater
            // than both, return true;
            else
                return true;
        }
        return false;
    }
};
