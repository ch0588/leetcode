/*
DP
l[i]:第0天至第i天，恰好只交易一次的最大收益，l[i]可由l[i-1]推出
r[i]:第i天至第n-1天，恰好只交易一次的最大收益，r[i]可由r[i+1]推出
O(n)枚举
*/
class Solution {
public:

    int maxProfit(vector<int> &prices) {
        int n = (int)prices.size();
        if(n==0) return 0;

        vector<int>l(n+1),r(n+1);
        int minPrice = prices[0];
        l[0] = 0;
        for(int i=1; i<n; ++i){
            minPrice = min(minPrice,prices[i]);
            l[i] = max(l[i-1],prices[i]-minPrice);
        }

        int maxPrice = prices[n-1];
        r[0] = 0;
        for(int i=n-2; i>=0; --i){
            maxPrice = max(maxPrice,prices[i]);
            r[i] = max(r[i+1],maxPrice-prices[i]);
        }

        int ret = l[n-1];
        for(int i=1; i<n; ++i)
            ret = max(ret, l[i-1]+r[i]);
        return ret;
    }
};
