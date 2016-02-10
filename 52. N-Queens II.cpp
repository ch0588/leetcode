// Time Complexity: O(n!)
// Space Complexity: O(n)

class Solution {
public:
    int lie[100], zhu[100], fu[100];
    int res;
    int path[100];
    void dfs(int d, int n) {
        if (d > n) {
            res++;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (lie[i] == false && zhu[i - d + 50] == false && fu[i + d] == false) {
                lie[i] = zhu[i - d + 50] = fu[i + d] = true;
                path[d] = i;
                dfs(d + 1, n);
                lie[i] = zhu[i - d + 50] = fu[i + d] = false;
            }
        }
    }
    int totalNQueens(int n) {
        memset(lie,false,sizeof(lie));
        memset(fu,false,sizeof(fu));
        memset(zhu,false,sizeof(zhu));
        res = 0;
        dfs(1, n);
        return res;
    }
};