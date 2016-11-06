/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.
*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int ans = 0;
        if(!grid.size())
            return ans;
        int dp[grid.size() + 2][grid[0].size() + 2][4];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < grid.size(); ++ i){
            for(int j = 0; j < grid[0].size(); ++ j){
                if(grid[i][j] == 'W')
                    dp[i + 1][j + 1][0] = dp[i + 1][j + 1][1] = 0;
                else {
                    dp[i + 1][j + 1][0] = dp[i + 1][j][0] + (grid[i][j] == 'E');
                    dp[i + 1][j + 1][1] = dp[i][j + 1][1] + (grid[i][j] == 'E');
                }
                // else if(grid[i][j] == '0'){
                //     dp[i + 1][j + 1][0] = dp[i + 1][j][0];
                //     dp[i + 1][j + 1][1] = dp[i][j + 1][1];
                // }else{
                //     dp[i + 1][j + 1][0] = dp[i + 1][j][0] + 1;
                //     dp[i + 1][j + 1][1] = dp[i][j + 1][1] + 1;
                // }
            }
        }
        
        for(int i = grid.size() - 1; i >= 0; -- i){
            for(int j = grid[0].size() - 1; j >= 0; -- j){
                if(grid[i][j] == 'W')
                    dp[i + 1][j + 1][0] = dp[i + 1][j + 1][1] = 0;
                else {
                    dp[i + 1][j + 1][2] = dp[i + 1][j + 2][2] + (grid[i][j] == 'E');
                    dp[i + 1][j + 1][3] = dp[i + 2][j + 1][3] + (grid[i][j] == 'E');
                }
            }
        }
        
        for(int i = 0; i < grid.size(); ++ i){
            for(int j = 0; j < grid[0].size(); ++ j){
                if(grid[i][j] == '0')
                    ans = max(ans, dp[i + 1][j + 1][0] + dp[i + 1][j + 1][1] + dp[i + 1][j + 1][2] + dp[i + 1][j + 1][3]);
            }
        }
        
        return ans;
    }
};