// 56. Merge Intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

    int n = intervals.size();
    if(n<2) return intervals;

    // this will have the merged intervals
    vector<vector<int>> merged;
    sort(intervals.begin(), intervals.end());
    for(int i =0; i<n; i++){

        // if overlapp, change the second value according to max of
        // the two overlapping as the first value of previous is surely
        // less than or equal to first value of i, no need to modify it
        if(i && intervals[i][0] <= merged.back()[1]){
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }

       else
        merged.push_back(vector<int>{intervals[i][0], intervals[i][1]});
    }

    return merged;
    }
};
