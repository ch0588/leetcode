class Solution {
public:

    int lie[100],zhu[100],fu[100];
    int path[100];
    vector<vector<string> >ret;
    void dfs(int d,int n){
        if(d>n){
            vector<string>ans;
            for(int i=0; i<n; ++i){
                string s="";
                for(int j=0; j<n; ++j){
                    if(path[i+1]==j+1) s+='Q';
                    else s+='.';
                }
                ans.push_back(s);
            }
            ret.push_back(ans);
            return;
        }
        for(int i=1; i<=n; ++i){
            if(lie[i]==false && zhu[i-d+50]==false && fu[i+d]==false){
                lie[i] = zhu[i-d+50] = fu[i+d] = true;
                path[d] = i;
                dfs(d+1,n);
                lie[i] = zhu[i-d+50] = fu[i+d] = false;
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        memset(lie,false,sizeof(lie));
        memset(fu,false,sizeof(fu));
        memset(zhu,false,sizeof(zhu));
        ret.clear();
        dfs(1,n);
        return ret;
    }
};
