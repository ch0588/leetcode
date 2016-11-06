/*
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.

Explanation:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6 
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Example:
Given m = 1, n = 1, return 9.

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/

class Solution {
public:
    void dfs(int cur, int depth, const int m, const int n) {
        if (depth > n) return;
        vis[cur] = true;
        if (depth >= m && depth <= n) 
            cnt++;
        
        for (int i = 1; i <= 9; ++i) {
            if (vis[i]) continue;
            int mid = skip[cur][i];
            if (mid != -1 && !vis[mid]) continue;
            dfs(i , depth + 1, m, n);
        }
        
        vis[cur] = false;
    }
    int numberOfPatterns(int m, int n) {
        init();
        int res = 0;
        cnt = 0;
        dfs(5, 1, m, n);
        res += cnt;
        cnt = 0;
        dfs(1, 1, m, n);
        res += 4 * cnt;
        cnt = 0;
        dfs(2, 1, m, n);
        res += 4 * cnt;
        return res;
    }
private:
    void init() {
        memset(skip, -1, sizeof(skip));
        skip[1][3] = 2;
        skip[4][6] = 5;
        skip[7][9] = 8;
        skip[1][7] = 4;
        skip[2][8] = 5;
        skip[3][9] = 6;
        skip[1][9] = 5;
        skip[3][7] = 5;
        
        skip[3][1] = 2;
        skip[6][4] = 5;
        skip[9][7] = 8;
        skip[7][1] = 4;
        skip[8][2] = 5;
        skip[9][3] = 6;
        skip[9][1] = 5;
        skip[7][3] = 5;
        
        memset(vis, false, sizeof(vis));
    }
    
    int skip[10][10];
    bool vis[10];
    int cnt = 0;
};