/*
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
 */

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // 0:red 1:blue 2:green
        int n = costs.size();
        if (n == 0) return 0;
        
        int dp[n][3];
        for (int i = 0; i < 3; ++i) dp[0][i] = costs[0][i];
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < 3; ++j) dp[i][j] = INT_MAX;
        
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k) {
                    if (j == k) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + costs[i][j]);
                }
        int res = INT_MAX;
        for (int i = 0; i < 3; ++i) res = min(res, dp[n - 1][i]);
        return res;
    }
};