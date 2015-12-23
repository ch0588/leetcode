/*
dp init isp[][] mean to whether s[i...j] is Partitioning time:O(n^2)
then dp mincut O(n^2)
*/
class Solution {
public:
    int **isp;
    string input;
    int dfs(int l,int r){
        if(isp[l][r]!=-1) return isp[l][r];
        if(l>r) return true;
        
        if(input[l]!=input[r]) return isp[l][r] = 0;
        return isp[l][r] = dfs(l+1,r-1);
    }
    int minCut(string s) {
        int n = s.size();
        if(n<=1) return 0;
        
        input = s;

        int dp[n];
        isp = new int*[n];
        for(int i=0; i<n; ++i)
            isp[i] = new int[n];
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)   
                isp[i][j] = -1;
            isp[i][i] = 1;
        }
                
        for(int i=0; i<n; ++i)
            for(int j=i; j<n; ++j)
                isp[i][j] = dfs(i,j);
                
        for(int i=0; i<n; ++i) dp[i] = INT_MAX;
        dp[0] = 0;
        for(int i=1; i<n; ++i){
            string t="";
            for(int j=i; j>=0; --j){
                if(isp[j][i]){
                    if(j==0) dp[i] = 0;
                    else dp[i] = min(dp[i],dp[j-1]+1);
                }
            }
        }
        return dp[n-1];
    }
};

/*枚举中点O(N^2)*/
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};