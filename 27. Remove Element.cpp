// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int en = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == val) en++;
            else nums[i-en] = nums[i];
        }
        return n-en;
    }
};