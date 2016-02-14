// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, n, m, i, j);
                }
            }
        return res;
    }
    int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int n, int m, int x, int y) {
        grid[x][y] = 'x';
        for (int i = 0; i < 4; ++i) {
            int nx = x + go[i][0];
            int ny = y + go[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '1') dfs(grid, n, m, nx, ny);
        }
    }
};