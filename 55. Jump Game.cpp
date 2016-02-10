// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;
        
        int maxPos = nums[0];
        for (int i = 0; i < n; ++i) {
            if (maxPos < i || maxPos >= n-1) break;
            maxPos = max(i + nums[i], maxPos);
        }
        return maxPos >= n - 1;
    }
    
};