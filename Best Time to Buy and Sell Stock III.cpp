/*
DP
l[i]:��0������i�죬ǡ��ֻ����һ�ε�������棬l[i]����l[i-1]�Ƴ�
r[i]:��i������n-1�죬ǡ��ֻ����һ�ε�������棬r[i]����r[i+1]�Ƴ�
O(n)ö��
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
