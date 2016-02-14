// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt == 0) {
                res = nums[i];
                cnt = 1;
            } else {
                if (res == nums[i])
                    cnt++;
                else
                    cnt--;
            }
        }
        return res;
    }
};