// 200. Number of Islands

class Solution {
// using dfs

    void removeIsland(vector<vector<char>>& grid, int i, int j){

        int n = grid.size(), m = grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        removeIsland(grid, i+1 , j);
        removeIsland(grid, i-1, j);
        removeIsland(grid, i, j+1);
        removeIsland(grid, i, j-1);
    }



public:
    int numIslands(vector<vector<char>>& grid) {

        int islands = 0;
        int n = grid.size();

        if(!n)
            return 0;

        int m = grid[0].size();

        for(int i = 0; i<n; i++){

            for(int j = 0; j<m; j++){

                if(grid[i][j] == '1'){
                    islands++;
                    removeIsland(grid, i, j);
                }
            }
        }

        return islands;
    }
};
