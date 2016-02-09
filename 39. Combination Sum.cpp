// Time Complexity: O(n!)
// Space Complexity: O(1)

class Solution {
public:
    vector<vector<int> >res;
    void dfs(vector<int> &candidates, int d, int sum, int target,vector<int>&path) {
        if (d >= (int)candidates.size()) return;
        if (sum > target) return;
        if (target==sum) {
            res.push_back(path);
            return;
        }
        
        path.push_back(candidates[d]);
        dfs(candidates, d, sum+candidates[d], target,path);
        path.pop_back();
        
        dfs(candidates, d+1, sum, target, path);
        
        
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        res.clear();
        vector<int>path;
        dfs(candidates, 0, 0, target, path);
        return res;
    }
};
