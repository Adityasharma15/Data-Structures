// 463. Island Perimeter

class Solution {

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();

        int walls_inside = 0, blocks = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(grid[i][j]){

                    blocks++;

                    if(i && grid[i-1][j])
                        walls_inside++;

                    if(j && grid[i][j-1])
                        walls_inside++;
                }
            }
        }

        // each block will contribute 4 lengths in perimeter, but if
        // it is connected so some other block, then number of such
        // walls need to be subtracted for both the blocks sharing that
        // wall.
        return 4*blocks - 2*walls_inside;
    }
};
