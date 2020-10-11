// 15. 3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int> > zero_sum;

        if(n < 3)
            return zero_sum;

        sort(nums.begin(), nums.end());

        // first fix an element ans search for a pair such that these 3
        // form the sum 0;
        // lets consider a triplet with sum 0: a, b, c & their positions :
        // i, j, k.
        for(int i = 0; i<n - 2; i++){

            int a = nums[i];

            // if a is greater than 0, no way any triplet can form zero
            // from here onwards, as nums is sorted.
            if(a > 0)
                break;

            // if it is equal to last element, this will result into dupilcacy
            // so we will skip this
            if(i>0 && nums[i] == nums[i-1])
                continue;

            int j = i+1, k = n-1;

            // now we are left with a typical binary search problem
            while(j<k){

                int b = nums[j], c = nums[k];

                if((a + b + ac) == 0){
                    vector<int> temp{a, b, c};
                    zero_sum.push_back(temp);

                    // there might be other triplets including a
                    // so we will increase j till num[j] == b
                    // & decrease k till num[k] == c to avoid duplicacy
                    while(j<k && b == nums[++j]);
                    while(k>j && c == nums[--k]);
                }

                else if((a+b+c) > 0){
                    k--;
                }

                else{
                    j++;
                }
            }
        }

        return zero_sum;
    }
};
