/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?
 */
class Solution {
public:
    int *fa;
    int find(int x){
        if(x==fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        fa = new int[m*n];
        vector<int>res;
        int num = 0;
        
        bool vis[m][n];
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j){
                fa[ n*i+j ] = n*i+j;
                vis[i][j] = false;
            }
        
        int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
        for( auto pos:positions ){
            int x = pos.first, y = pos.second;
            if(vis[x][y]) continue;
            vis[x][y] = true;
            num++;
            for(int k=0; k<4; ++k){
                int nx = x+go[k][0];
                int ny = y+go[k][1];
                if(nx<0||nx>=m || ny<0||ny>=n) continue;
                int id = n*x+y;
                if(vis[nx][ny]){
                    int nf = find( n*nx+ny );
                    if(nf!=id){
                        num--;
                        fa[nf] = id;
                    }
                }
            }
            res.emplace_back(num);
        }
        return res;
    }
};