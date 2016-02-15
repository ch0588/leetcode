class Solution {
public:
    vector<vector<int>> ans;
    int rsum[10];
    void dfs(int pos, int n, int k, vector<int> cur, int cursum) {
        if (cursum > n) return;
        int delta = k - cur.size();
        if (9 - pos < delta) return;
        if (cursum + rsum[9 - delta] < n) return;
        if (cursum + (pos + 1) * delta > n) return;
        
        if (delta == 0) {
            if (cursum == n) ans.push_back(cur);
            return;
        }
        for (int i = pos + 1; i < 10; ++i) {
            cur.push_back(i);
            dfs(i, n, k, cur, cursum + i);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k < 0 || k > 9) return res;
        rsum[9] = 9;
        for (int i = 8; i >= 0; --i) rsum[i] = i + rsum[i + 1];
        
        ans.clear();
        vector<int> cur;
        dfs(0, n, k, cur, 0);
        return ans;
    }
};