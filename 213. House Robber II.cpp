// Time Complexity: O(n)
// Space Complexity: O(n)

/*
 This is an extension of House Robber.
 
 as the circle, concern arrary nums [0,n-1].the result is max( [1,n-1],[0,n-2] )
 */
class Solution {
public:
    int rob1(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> t;
        for (int i = 0; i < n - 1; ++i) t.push_back(nums[i]);
        int res = rob1(t);
        t.clear();
        for (int i = 1; i < n; ++i) t.push_back(nums[i]);
        res = max(res, rob1(t));
        return res;
    }
};