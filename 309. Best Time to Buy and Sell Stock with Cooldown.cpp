/*
https://leetcode.com/discuss/71354/share-my-thinking-process
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        /*
        buy[i] = max(sell[i-2]-price, buy[i-1])
        sell[i] = max(buy[i-1]+price, sell[i-1])
        */
        int buy[n],sell[n];
        buy[0] = -prices[0];
        buy[1] = max(-prices[1],buy[0]);
        sell[0] = 0;
        sell[1] = max(buy[0]+prices[1],sell[0]);
        for(int i=2; i<n; ++i){
            buy[i] = max(sell[i-2]-prices[i], buy[i-1]);
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]);
        }
        return max(buy[n-1],sell[n-1]);
    }
};