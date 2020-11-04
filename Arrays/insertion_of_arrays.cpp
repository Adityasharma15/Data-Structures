// 349. Intersection of Two Arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> intersection;
        unordered_set<int> first(nums1.begin(), nums1.end());

        for(auto i : nums2){

            if(first.count(i)){
                intersection.push_back(i);
                first.erase(first.find(i));
            }
        }

        return intersection;
    }
};
