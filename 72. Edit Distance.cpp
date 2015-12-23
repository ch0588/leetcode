class Solution {
public:
    int **dp;
    string w1,w2;
    int dfs(int pos1,int pos2){
        if(pos1<0 && pos2<0) return 0;
        if(pos1<0) return pos2+1;
        if(pos2<0) return pos1+1;
        if(dp[pos1][pos2]!=-1) return dp[pos1][pos2];
        
        int t = dfs(pos1-1,pos2-1) + (w1[pos1]==w2[pos2]?0:1);
        t = min(t,dfs(pos1-1,pos2)+1);
        t = min(t,dfs(pos1,pos2-1)+1);
        return dp[pos1][pos2] = t;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        w1 = word1;
        w2 = word2;
        dp = new int*[n];
        for(int i=0; i<n; ++i)
            dp[i] = new int[m];
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                dp[i][j] = -1;
        return dfs(n-1,m-1);
    }
};