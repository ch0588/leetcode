/*
 O(N)*hash，类似滑动窗口
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; ++i) {
            if (i > k) hash[nums[i - k - 1]]--;
            if (hash[nums[i]] > 0) return true;
            hash[nums[i]]++;
        }
        return false;
    }
};