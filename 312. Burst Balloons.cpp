/*
dp[i][j] means after burst all bll between i...j,the max value
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        
        int dp[n+2][n+2]={0};
  
            
        for(int len=1; len<=n; ++len)
            for(int left=1; left+len-1<=n; ++left){
                int right = left+len-1;
                for(int i=left; i<=right; ++i){
                    dp[left][right] = max(dp[left][right],nums[i]*nums[left-1]*nums[right+1]+dp[left][i-1]+dp[i+1][right]);
                }
            }
        return dp[1][n];
    }
};