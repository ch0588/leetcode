// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

class Solution {
public:
    int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& f, int i, int j,
            int n, int m) {
        if (f[i][j] > 0) return f[i][j];
        
        int res = 0;
        for (int k = 0; k < 4; ++k) {
            int x = i + go[k][0];
            int y = j + go[k][1];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (matrix[x][y] > matrix[i][j]) {
                res = max(res, dfs(matrix, f, x, y, n, m));
            }
        }
        return f[i][j] = res + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        
        vector<vector<int>> f(n, vector<int>(m, 0));
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) res = max(res, dfs(matrix, f, i, j, n, m));
        return res;
    }
};