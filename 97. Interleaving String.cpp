/*
https://leetcode.com/discuss/11694/my-dp-solution-in-c
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1+n2!=s3.size()) return false;
        
        bool dp[n1+1][n2+1];
        memset(dp,false,sizeof(dp));
        for(int i=0; i<=n1; ++i)
            for(int j=0; j<=n2; ++j){
                if(i==0 && j==0) dp[i][j] = true;
                else if(i==0) dp[i][j] = dp[i][j-1] && s2[j-1]==s3[i+j-1];
                else if(j==0) dp[i][j] = dp[i-1][j] && s1[i-1]==s3[i+j-1];
                else{
                    dp[i][j] = (dp[i-1][j]&&s1[i-1]==s3[i+j-1]) || (dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
                }
            }
        return dp[n1][n2];
    }
};