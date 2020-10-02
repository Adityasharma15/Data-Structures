// 118. Pascal's Triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int> > pascal(numRows, vector<int>());

        if(!numRows)
            return pascal;

        pascal[0].push_back(1);

        // column
        for(int i = 1; i<numRows; i++){

            pascal[i].push_back(1);

            // row
            for(int j = 0; j<i-1; j++){
                pascal[i].push_back(pascal[i-1][j] + pascal[i-1][j+1]);
            }

            pascal[i].push_back(1);
        }

        return pascal;
    }
};
