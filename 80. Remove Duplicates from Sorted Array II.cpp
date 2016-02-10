// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        
        int i = 0, j = 1;
        bool first = true;
        int res = 0;
        while (j < n) {
            while (j < n && nums[i] == nums[j]) {
                if (first) {
                    nums[++i] = nums[j];
                }
                first = false;
                j++;
            }
            first = true;
            if (j < n) nums[++i] = nums[j++];
        }
        return i + 1;
    }
};