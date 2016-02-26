/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?

Show Company Tags
Show Tags
Show Similar Problems
 */


// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> hash;
        int cur_sum = 0;
        for (int i = 0; i < n; ++i) {
            cur_sum += nums[i];
            if (cur_sum == k) res = i + 1;
            
            if (hash.find(cur_sum - k) != hash.end()) {
                res = max(res, i - hash[cur_sum - k]);
            }
            if (hash.find(cur_sum) ==
                hash.end()) {  // maintain hash value is the first pos
                hash[cur_sum] = i;
            }
        }
        return res;
    }
};