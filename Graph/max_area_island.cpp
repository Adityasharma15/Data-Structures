// 695. Max Area of Island

class Solution {
int n , m;

    int max_island(vector<vector<int> > & grid, int i , int j){

        // if it going out of land area, return 0
        if(i<0 || i>=n || j<0 || j>=m || !grid[i][j])
            return 0;

        // important to mark an element done
        grid[i][j] = 0;

        // call to all directions and then calculate the total land are
        return (max_island(grid, i+1, j) + max_island(grid, i-1, j) + max_island(grid, i, j+1) + max_island(grid, i, j-1)) + 1;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        n = grid.size();
        if(!n) return 0;
        m = grid[0].size();

        // traversing on every 1
        int max_size = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(grid[i][j]){
                    max_size = max(max_size, max_island(grid, i, j));
                }
            }
        }

        return max_size;
    }
};
