class Solution {
public:
    vector<vector<int> >ret;
    void dfs(vector<int> &candidates, int d, int sum, int target,vector<int>&path){
        if(d>=(int)candidates.size()) return;
        if(sum>target) return;
        if(target==sum){
            ret.push_back(path);
            return;
        }

        path.push_back(candidates[d]);
        dfs(candidates,d,sum+candidates[d],target,path);
        path.pop_back();

        dfs(candidates,d+1,sum,target,path);


    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        ret.clear();
        vector<int>path;
        path.clear();
        dfs(candidates,0,0,target,path);
        return ret;
    }
};
