// 47. Permutations II

class Solution {

    bool nextPermutation(vector<int> & nums){

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
         return false;
     } else{

         for(i = n-1; i>=0; i--){

             if(nums[i] > nums[smallest_from_right])
                break;
         }

         swap(nums[i] , nums[smallest_from_right]);
         reverse(nums.begin()+ smallest_from_right + 1, nums.end());
     }

        return true;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // we will keep on finding the next permutations.
        // as there are total n! permutations

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > permutations;
            do{
            permutations.push_back(nums);
            } while(nextPermutation(nums));

        return permutations;
    }
};
