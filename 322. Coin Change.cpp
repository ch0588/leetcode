class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n==0) return 0;
        int dp[amount+1];
        int Max = amount+1;
    

        for(int j=0; j<=amount; ++j)
            dp[j] = Max;
        dp[0] = 0;
        
        for(int i=0; i<n; ++i)
            for(int j=0; j<=amount; ++j){
                if( j>=coins[i] )
                    dp[j] = min(dp[j],dp[j-coins[i]]+1);
            }
        return dp[amount]==Max?-1:dp[amount];
    }
};