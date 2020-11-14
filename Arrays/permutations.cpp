// 46. Permutations

class Solution {

    void nextPermutation(vector<int> & nums){

     int n = nums.size(), i;
     int smallest_from_right;
     for(i = n-2; i>=0; i--){

         if(nums[i] < nums[i+1]){
             smallest_from_right = i;
             break;
         }

     }

     if(i<0){
         reverse(nums.begin(), nums.end());
     } else{

         for(i = n-1; i>=0; i--){

             if(nums[i] > nums[smallest_from_right])
                break;
         }

         swap(nums[i] , nums[smallest_from_right]);
         reverse(nums.begin()+ smallest_from_right + 1, nums.end());
     }

        return;
    }

    int factorial(int n){
        int fac = n;

        while(--n){
            fac *= n;
        }

        return fac;
    }


public:
    vector<vector<int>> permute(vector<int>& nums) {

        // we will keep on finding the next permutations.
        // as there are total n! permutations

        int n = nums.size();
        int fac = factorial(n);
        vector<vector<int> > permutations;
        while(fac--){
            permutations.push_back(nums);
            nextPermutation(nums);
        }

        return permutations;
    }
};
