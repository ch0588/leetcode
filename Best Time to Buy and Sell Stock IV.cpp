/*
当k>=N/2，实质上可以买卖无限多次，同第二题。
当k<N/2时，需要DP
设原始数据存于prices[1...n]数组中
f[i][k]表示用prices中的[1..i]天数据，交易k次的最大收益。
转移方程为：
f[i][k] = max(f[i][k-1],max(f[i-1][k],f[j-1][k-1] + prices[i] - prices[j]))
移项后得到：
f[i][k] = max(f[i][k-1],max(f[i-1][k],prices[i] + (f[j-1][k-1] - prices[j]) ))
(f[j-1][k-1]-prices[j])用变量max_cur代替，max_cur可以边计算边维护，所有时间算法复杂度为O(kN).
滚动数组节省空间，空间复杂度为O(N).
*/
class Solution {
public:
    int allSell(vector<int> &prices) {
        int ret = 0;
        for(int i=1; i<prices.size(); ++i)
            if(prices[i]-prices[i-1]>0) ret += (prices[i]-prices[i-1]);
        return ret;
    }
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if(k>=n/2){
            return allSell(prices);
        }

        prices.push_back(0);
        for(int i=n; i>=1; i--) prices[i] = prices[i-1]; //make sure prices's index start from 1

        int f[n+1][2];
        memset(f,0,sizeof(f));

        int now = 0;
        for(int j=1; j<=k; ++j){
            int max_cur = INT_MIN;
            f[0][now] = 0;
            for(int i=1; i<=n; ++i){
                f[i][now] = max(f[i][1-now],max(f[i-1][now],prices[i]+max_cur));
                max_cur = max(max_cur,f[i-1][1-now]-prices[i]);
            }
            now = 1-now;
        }
        return f[n][1-now];
    }
};
