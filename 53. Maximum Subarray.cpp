// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int res = nums[0];
        int t =0 ;
        for (int i=0; i < n; ++i) {
            t += nums[i];
            res = max(res, t);
            if (t < 0) t = 0;
        }
        return res;
    }
};
