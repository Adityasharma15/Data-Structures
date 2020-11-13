// 1122. Relative Sort Array

class Solution {

// as we have the max value 1000, we can do something like
// count sort.

public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int> sorted;
        vector<int> frequency(1001, 0);
        for(auto num1: arr1){
            frequency[num1]++;
        }

        for(auto num2: arr2){

            while(frequency[num2]){
                sorted.push_back(num2);
                frequency[num2]--;
            }
        }


        for(int i = 0; i<1001; i++){

            while(frequency[i]--){
                sorted.push_back(i);
            }
        }

        return sorted;
    }
};
