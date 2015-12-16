class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0; i<=n; ++i){
            dp[i] = INT_MAX;
            int t = sqrt(i);
            if(t*t==i) dp[i] = 1;
            
            for(int j=1; j*j<i; ++j)
                dp[i] = min(dp[i],dp[i-j*j] + 1);
        }
        return dp[n];
    }
};