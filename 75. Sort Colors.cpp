// Time Complexity: O(n)
// Space Complexity: O(1)

//one-pass algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        for (int i = 0; i < n; ++i) {
            while (nums[i] == 2 && i < r)  // two while order can't change
                swap(nums[i], nums[r--]);
            while (nums[i] == 0 && i > l) swap(nums[i], nums[l++]);
        }
    }
};

// r循环再前面，因为将未知数据扔到后面，之后i递增时会再次处理