/*
2 2 2,4
only ans [2,2]
一个候选元素，只有前面和他值相等的的都用了，他才能用
*/
class Solution {
public:
    vector<vector<int> >ret;
    void dfs(vector<int> &candidates, int d, int sum, int target,vector<int>&path){

        if(target==sum){
            ret.push_back(path);
            return;
        }
        if(d>=(int)candidates.size()) return;
        if(sum>target) return;


        int cntpath=0,cntcan=0;
        for(int i=path.size()-1; i>=0; --i) {
            if(path[i]==candidates[d]) cntpath++;
            else break;
        }
        for(int i=d-1; i>=0; --i) {
            if(candidates[i]==candidates[d]) cntcan++;
            else break;
        }
        if(cntpath==cntcan){
            path.push_back(candidates[d]);
            dfs(candidates,d+1,sum+candidates[d],target,path);
            path.pop_back();
        }

        dfs(candidates,d+1,sum,target,path);
    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        ret.clear();
        vector<int>path;
        path.clear();
        dfs(candidates,0,0,target,path);
        return ret;
    }
};
