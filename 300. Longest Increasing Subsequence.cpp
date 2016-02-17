// Time Complexity: O(logn)
// Space Complexity: O(n)

/*
 https://leetcode.com/discuss/67533/c-typical-dp-2-solution-and-nlogn-solution-from-geekforgeek
 res[i] means the min last value which lenght i sequence
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (auto item : nums) {
            auto it = lower_bound(res.begin(), res.end(), item);
            if (it == res.end())
                res.push_back(item);
            else
                *it = item;
        }
        return res.size();
    }
};