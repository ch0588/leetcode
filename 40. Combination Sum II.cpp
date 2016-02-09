// Time Complexity: O(n!)
// Space Complexity: O(1)

/*
 2 2 2,4
 only ans [2,2]
 one candidate element can be used only when the element before it all be used
 */
class Solution {
public:
    vector<vector<int> >res;
    void dfs(vector<int> &candidates, int d, int sum, int target, vector<int>&path){
        
        if (target == sum) {
            res.push_back(path);
            return;
        }
        if (d >= (int)candidates.size()) return;
        if (sum > target) return;
        
        
        int cntpath=0, cntcan=0;
        for (int i=path.size() - 1; i >= 0; --i) {
            if (path[i] == candidates[d]) cntpath++;
            else break;
        }
        for (int i = d-1; i >= 0; --i) {
            if (candidates[i] == candidates[d]) cntcan++;
            else break;
        }
        if (cntpath == cntcan){
            path.push_back(candidates[d]);
            dfs(candidates,d+1,sum+candidates[d],target,path);
            path.pop_back();
        }
        
        dfs(candidates, d+1, sum, target, path);
    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        res.clear();
        vector<int>path;
        dfs(candidates, 0, 0, target, path);
        return res;
    }
};
