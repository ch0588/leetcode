// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int dp[n][2] = {0};  // 0 don't rob this house, 1 rob
        dp[0][1] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};