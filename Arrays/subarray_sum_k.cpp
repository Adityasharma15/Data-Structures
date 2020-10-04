// 560. Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int prefix_sum = 0;
        unordered_map<int, int> sum_frequency;
        sum_frequency[0]++;
        int subarrays = 0;

        for(int i = 0; i< nums.size(); i++){
            prefix_sum+= nums[i];

            // if there is a subarray with sum k uptill now
            if(sum_frequency.find(prefix_sum - k) != sum_frequency.end()){
                subarrays+=sum_frequency[prefix_sum - k];
            }
            sum_frequency[prefix_sum]++;
        }

        return subarrays;
    }
};
