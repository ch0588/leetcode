class Solution {
public:
    vector<vector<int> >ret;
    vector<int>a,num;

    void dfs(int d,vector<int>path){
        if(d>=(int)a.size()){
            vector<int>temp;
            for(int i=0; i<path.size(); ++i)
                for(int j=0; j<path[i]; ++j)
                    temp.push_back( a[i] );
            ret.push_back(temp);
            return;
        }
        for(int i=0; i<=num[d]; ++i){
            path.push_back(i);
            dfs(d+1,path);
            path.pop_back();
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        ret.clear();
        a.clear();
        num.clear();

        if((int)S.size()==0) return ret;

        sort(S.begin(),S.end());
        int pre = S[0], t = 1;
        for(int i=1; i<S.size(); ++i){
            if(pre==S[i]){
                t++;
            }
            else{
                a.push_back(pre);
                num.push_back(t);
                t=1;
                pre = S[i];
            }
        }
        a.push_back(pre);
        num.push_back(t);

        vector<int>path;
        dfs(0,path);
        return ret;
    }
};
