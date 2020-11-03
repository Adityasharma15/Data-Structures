// 73. Set Matrix Zeroes

class Solution {

// as m & n are less than 201, then we can create a boolean
// vector for row and column depicting whether 0 has occured
// in that row/col or not

public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<bool> row(n, false);
        vector<bool> col(m, false);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(!matrix[i][j]){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }

        return;
    }
};
