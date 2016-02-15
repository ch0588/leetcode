// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        if (n == 0) return res;
        int start = nums[0], end = start;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1)
                end = nums[i];
            else {
                if (start < end)
                    res.push_back(to_string(start) + "->" + to_string(end));
                else
                    res.push_back(to_string(start));
                start = end = nums[i];
            }
        }
        if (start < end)
            res.push_back(to_string(start) + "->" + to_string(end));
        else
            res.push_back(to_string(start));
        return res;
    }
};