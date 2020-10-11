// 16. 3Sum Closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        if(n < 3)
            return 0;

        // starting with a random value
        int closest = nums[0] + nums[1] + nums[3];
        sort(nums.begin(), nums.end());

        // first fix an element ans search for a pair such that these 3
        // form the sum 0;
        // lets consider a triplet with sum 0: a, b, c & their positions :
        // i, j, k.
        for(int i = 0; i<n-2; i++){

            int a = nums[i];
            int j = i+1, k = n-1;

            // now we are left with a typical binary search problem
            while(j<k){

                int b = nums[j], c = nums[k];
                int sum = a+ b+ c;

                // if diff bw target is less for this sum, update this sum as
                // closest uptill now
                if(abs(target - sum) < abs(target - closest)){
                    closest = sum;
                }

                if(sum > target){
                    k--;
                }

                else{
                    j++;
                }
            }
        }

        return closest;

    }
};
