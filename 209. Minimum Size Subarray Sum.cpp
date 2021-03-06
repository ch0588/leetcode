// Time Complexity: O(n)
// Space Complexity: O(1)

/*
 two pointer
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int start = 0, sum = 0;
        int res = n + 1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            while (sum >= s) {
                res = min(res, i - start + 1);
                sum -= nums[start++];
            }
        }
        return res == n + 1 ? 0 : res;
    }
};