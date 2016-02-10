// Time Complexity: O(mn)
// Space Complexity: O(mn)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = obstacleGrid.size();
        if (n < 1) return 0;
        int m = obstacleGrid[0].size();
        if (m < 1) return 0;
        
        if(obstacleGrid[0][0] || obstacleGrid[n - 1][m - 1]) return 0;
        
        int f[n][m] = {0};
        f[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[0][i] ) f[0][i] = 0;
            else f[0][i] = f[0][i - 1];
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[i][0] ) f[i][0] = 0;
            else f[i][0] = f[i - 1][0];
        }
        
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j){
                if(obstacleGrid[i][j])
                    f[i][j] = 0;
                else
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        return f[n - 1][m - 1];
    }
};
