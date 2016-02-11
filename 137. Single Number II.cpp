// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt[32] = {0};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 32; ++j) {
                cnt[j] += ((nums[i] >> j) & 1);
                cnt[j] %= 3;
            }
        
        int res = 0;
        for (int i = 0; i < 32; ++i)
            if (cnt[i] != 0) res += ((1 << i) * cnt[i]);
        
        return res;
    }
};
