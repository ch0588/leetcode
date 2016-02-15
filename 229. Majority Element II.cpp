// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    //[1,2,2,3,2,1,1,3]
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int cnt[2] = {0}, res[2] = {INT_MIN, INT_MIN};
        
        for (int i = 0; i < n; ++i) {
            if (cnt[0] && nums[i] == res[0]) {
                cnt[0]++;
                continue;
            }
            if (cnt[1] && nums[i] == res[1]) {
                cnt[1]++;
                continue;
            }
            if (cnt[0] == 0) {
                cnt[0] = 1;
                res[0] = nums[i];
            } else if (cnt[1] == 0) {
                cnt[1] = 1;
                res[1] = nums[i];
            } else {
                cnt[0]--;
                cnt[1]--;
            }
        }
        
        cnt[0] = cnt[0] == 0 ? -n : 0;
        cnt[1] = cnt[1] == 0 ? -n : 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == res[0]) cnt[0]++;
            if (nums[i] == res[1])
                cnt[1]++;  // must else if!!! [-1,1,1,1,2,1] or will get double 1
        }
        vector<int> ans;
        if (cnt[0] > n / 3) ans.push_back(res[0]);
        if (cnt[1] > n / 3) ans.push_back(res[1]);
        return ans;
    }
};