// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res ^= nums[i];
        }
        return res;
    }
};
