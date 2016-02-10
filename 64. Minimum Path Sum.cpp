// Time Complexity: O(mn)
// Space Complexity: O(mn)

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size();
        if (n == 0) return false;
        int m = grid[0].size();
        
        int f[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                f[i][j] = INT_MAX;
        
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) f[0][i] = f[0][i-1] + grid[0][i];
        for (int i = 1; i < n; ++i) f[i][0] = f[i-1][0] + grid[i][0];
        
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
        
        return f[n-1][m-1];
    }
};
