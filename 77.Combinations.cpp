class Solution {
public:
    void dfs(vector<vector<int>>&res,int n,int k,int pos,vector<int>&now){
        if( (int)now.size()>=k ){
            res.push_back(now);
            return;
        }
        for(int i=pos; i<=n; ++i){
            now.push_back(i);
            dfs(res,n,k,i+1,now);
            now.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        if(k>n) return res;
        vector<int>now;
        dfs(res, n, k, 1, now);
        return res;
    }
};