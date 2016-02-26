/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
 */
class Solution {
    struct NODE {
        int x, y, t;
        NODE() {}
        NODE(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
    };
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        int res = INT_MAX;
        int sumhouse = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1) sumhouse++;
        
        int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) continue;
                queue<NODE> Q;
                bool vis[n][m];
                memset(vis, false, sizeof(vis));
                Q.push(NODE(i, j, 0));
                vis[i][j] = 0;
                int nhouse = 0, curdist = 0;
                while (!Q.empty()) {
                    NODE now = Q.front();
                    Q.pop();
                    if (grid[now.x][now.y] == 1) {
                        nhouse++;
                        curdist += now.t;
                        continue;
                    }
                    for (int k = 0; k < 4; ++k) {
                        int x = now.x + go[k][0];
                        int y = now.y + go[k][1];
                        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 2 ||
                            vis[x][y])
                            continue;
                        Q.push(NODE(x, y, now.t + 1));
                        vis[x][y] = true;
                    }
                }
                
                if (nhouse == sumhouse) {
                    res = min(res, curdist);
                }
            }
        return res == INT_MAX ? -1 : res;
    }
};

// Time:  O(k * m * n), k is the number of the buildings
// Space: O(m * n)
class Solution {
public:
    int shortestDistance(vector<vector<int>> grid) {
        int m = grid.size(), n = grid[0].size();
        auto total = grid;
        int walk = 0, mindist, delta[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    mindist = -1;
                    auto dist = grid;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    while (q.size()) {
                        auto ij = q.front();
                        q.pop();
                        for (int d = 0; d < 4; ++d) {
                            int i = ij.first + delta[d];
                            int j = ij.second + delta[d + 1];
                            if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
                                grid[i][j]--;
                                dist[i][j] = dist[ij.first][ij.second] + 1;
                                total[i][j] += dist[i][j] - 1;
                                q.emplace(i, j);
                                if (mindist < 0 || mindist > total[i][j]) mindist = total[i][j];
                            }
                        }
                    }
                    walk--;
                }
            }
        }
        return mindist;
    }
};