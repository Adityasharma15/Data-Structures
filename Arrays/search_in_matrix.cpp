// 74. Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // just consider the whole matrix as a sorted list.

        int row_num = matrix.size();

        if(row_num<=0)
            return false;

        int col_num = matrix[0].size();

        if(col_num <=0)
            return false;

        int start = 0, end = col_num*row_num - 1;

        while(start <= end)
        {
            int mid = (start + end)/2;

            // consider columm major
            int mid_val = matrix[mid/col_num][mid%col_num];

            // don't dare put mid - 1 here
            if(mid_val < target)
                start = mid + 1;

            else if(mid_val > target)
                end = mid - 1;

            else
                return true;
        }

        return false;
    }
};
