class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>t = nums;
        sort(nums.begin(),nums.end());
        int l = 0, r = n - 1;
        while (l < r) {
            if (nums[l] + nums[r] == target) {
                vector<int>res;
                for (int i = 0; i < n; ++i) {
                    if (t[i] == nums[l] || t[i] == nums[r]) 
                        res.emplace_back(i + 1);
                }
                return res;
            } else if (nums[l] + nums[r] < target) {
                l++;
            } else {
                r--;
            }
        }
        return vector<int>{};
    }
};