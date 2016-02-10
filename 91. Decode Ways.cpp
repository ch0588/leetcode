// Time Complexity: O(n)
// Space Complexity: O(1)

/*
 特殊考虑0
 */

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (s[0] == '0') return 0;
        if (n == 1) return 1;
        
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 0;
        if (10 * (s[0] - '0') + s[1] - '0' <= 26) dp[1]++;
        if (s[1] - '0' != 0) dp[1]++;
        
        for (int i = 2; i < n; ++i) {
            int x = 10 * (s[i - 1] - '0') + s[i] - '0';
            dp[i] = (x <= 26 && x >= 10) ? dp[i - 2] : 0;
            int y = s[i] - '0';
            dp[i] += (y != 0 ? dp[i - 1] : 0);
        }
        
        return dp[n - 1];
    }
};