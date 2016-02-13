// Time Complexity: O(n)
// Space Complexity: O(n)

// dp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int nmax[n], nmin[n], res;
        res = nmax[0] = nmin[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            nmax[i] = nmin[i] = nums[i];
            if (nums[i] > 0) {
                nmax[i] = max(nmax[i], nmax[i - 1] * nums[i]);
                nmin[i] = min(nmin[i], nmin[i - 1] * nums[i]);
            } else {
                nmax[i] = max(nmax[i], nmin[i - 1] * nums[i]);
                nmin[i] = min(nmin[i], nmax[i - 1] * nums[i]);
            }
            res = max(res, nmax[i]);
        }
        return res;
    }
};