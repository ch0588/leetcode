/*
 There is a fence with n posts, each post can be painted with one of the k
 colors.
 
 You have to paint all the posts such that no more than two adjacent fence posts
 have the same color.
 
 Return the total number of ways you can paint the fence.
 
 Note:
 n and k are non-negative integers.
 */

/*
 Need two one-dimensional array dp1 and dp2, dp1[i] means the number of solutions
 when the color of last two fences (whose indexes are i-1,i-2) are same. dp2[i]
 means the number of solutions when the color of last two fences are different.
 */

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int numWays(int n, int k) {
        if (n <= 1 || k == 0) return n * k;
        int dp1[n + 1] = {0}, dp2[n + 1] = {0};
        dp1[1] = dp2[1] = k;
        for (int i = 2; i <= n; ++i) {
            dp1[i] = dp2[i - 1];
            dp2[i] = (k - 1) *
            (dp2[i - 2] + dp2[i - 1]);  // dp2[i]=(k-1)(dp1[i-1]+dp2[i-1])
            // =(k-1)(dp2[i-2]+dp2[i-1])
        }
        return dp1[n] + dp2[n];
    }
};