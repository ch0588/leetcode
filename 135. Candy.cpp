// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;
        vector<int> nums(n, 1);
        for (int i = 1; i < n; ++i)
            if (ratings[i] > ratings[i - 1]) nums[i] = nums[i - 1] + 1;
        
        for (int i = n - 2; i >= 0; --i)
            if (ratings[i] > ratings[i + 1]) nums[i] = max(nums[i + 1] + 1, nums[i]);
        
        int res = 0;
        for (int i = 0; i < n; ++i) res += nums[i];
        return res;
    }
};