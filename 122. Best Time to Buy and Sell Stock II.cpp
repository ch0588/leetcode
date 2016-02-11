// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int res = 0;
        for (int i = 1; i < n; ++i)
            if (prices[i] - prices[i - 1] > 0)
                res += (prices[i] - prices[i - 1]);
        return res;
    }
};
