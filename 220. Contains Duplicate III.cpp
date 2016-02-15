/*
 用set来夹逼
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n  = nums.size();
        if (k == 0 || t < 0 || nums.size() < 2) return false;
        set<int> hash;
        for (int i = 0; i < n; ++i) {
            if (i > k) hash.erase(nums[i - k - 1]);
            auto lower = hash.lower_bound(nums[i] - t);
            if (lower != hash.end() && abs(*lower - nums[i]) <= t) return true;
            hash.insert(nums[i]);
        }
        return false;
    }
};