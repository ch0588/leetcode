/*
 search and cut branch
 
 dp
 */

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        int n = s1.size();
        
        int cnt[26] = {0};
        for (int i = 0; i < n; ++i) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i)
            if (cnt[i] != 0) return false;
        
        for (int i = 1; i < n; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i)))
                return true;
        }
        return false;
    }
};

// Time Complexity: O(n^4),  due to enumeration of n, i, j, k in (f[n][i][j] and k)
// Space Complexity: O(n^3), due to hash of f[n][i][j]

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if ((int)s2.size() != n) return false;
        
        bool dp[n + 1][n + 1][n + 1];
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                dp[i][j][1] = s1[i] == s2[j];
                for (int k = 2; k <= n; ++k) dp[i][j][k] = false;
            }
        
        for (int len = 2; len <= n; len++)
            for (int i = 0; i < n - len + 1; i++)
                for (int j = 0; j < n - len + 1; j++)
                    for (int k = 1; k < len; k++)
                        dp[i][j][len] |= (dp[i][j][k] && dp[i + k][j + k][len - k]) ||
                        (dp[i][j + len - k][k] && dp[i + k][j][len - k]);
        return dp[0][0][n];
    }
};