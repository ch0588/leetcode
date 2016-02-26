/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
Show Company Tags
Show Tags
Show Similar Problems
*/


// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

class Solution {
private:
    struct NODE {
        int x, y, t;
        NODE() {}
        NODE(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
    };
    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int INF = 2147483647;
        int n = rooms.size();
        if (n == 0) return;
        int m = rooms[0].size();
        
        int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int vis[n][m];
        NODE now;
        queue<NODE> Q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                vis[i][j] = 0;
                if (rooms[i][j] == 0) {
                    Q.push(NODE(i, j, 0));
                    vis[i][j] = 1;
                }
            }
        while (!Q.empty()) {
            now = Q.front();
            rooms[now.x][now.y] = now.t;
            Q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = now.x + go[k][0];
                int y = now.y + go[k][1];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (rooms[x][y] == -1 || vis[x][y] == 1) continue;
                Q.push(NODE(x, y, now.t + 1));
                vis[x][y] = 1;
            }
        }
    }
};