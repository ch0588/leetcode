/*
��k>=N/2��ʵ���Ͽ����������޶�Σ�ͬ�ڶ��⡣
��k<N/2ʱ����ҪDP
��ԭʼ���ݴ���prices[1...n]������
f[i][k]��ʾ��prices�е�[1..i]�����ݣ�����k�ε�������档
ת�Ʒ���Ϊ��
f[i][k] = max(f[i][k-1],max(f[i-1][k],f[j-1][k-1] + prices[i] - prices[j]))
�����õ���
f[i][k] = max(f[i][k-1],max(f[i-1][k],prices[i] + (f[j-1][k-1] - prices[j]) ))
(f[j-1][k-1]-prices[j])�ñ���max_cur���棬max_cur���Ա߼����ά��������ʱ���㷨���Ӷ�ΪO(kN).
���������ʡ�ռ䣬�ռ临�Ӷ�ΪO(N).
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
