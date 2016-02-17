// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            if (nums[i]) swap(nums[l++], nums[i]);
    }
};