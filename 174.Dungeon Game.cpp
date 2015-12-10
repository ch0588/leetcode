class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (!dungeon.size() || !dungeon[0].size())
            return 1;
        int n = dungeon.size();
        int m = dungeon[0].size();
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; ++i)
            for(int j=0; j<=m; ++j)
                dp[i][j] = INT_MAX;
                
        dp[n][m-1] = dp[n-1][m] = 1;
        for(int i=n-1; i>=0; --i)
            for(int j=m-1; j>=0; --j){
                dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = max(dp[i][j],1);
            }
        return dp[0][0];
    }
};