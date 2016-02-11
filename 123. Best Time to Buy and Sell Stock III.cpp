// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int l[n + 1], r[n + 1];
        int minPrice = prices[0];
        l[0] = 0;
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            l[i] = max(l[i - 1], prices[i] - minPrice);
        }
        
        int maxPrice = prices[n - 1];
        r[n-1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            r[i] = max(r[i + 1], maxPrice - prices[i]);
        }
        
        int res = l[n - 1];
        for (int i = 1; i < n; ++i) res = max(res, l[i - 1] + r[i]);
        return res;
    }
};
