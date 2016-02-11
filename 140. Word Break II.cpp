// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    vector<int> f;
    vector<string> ret;
    int dfs(int x, string s, unordered_set<string> &dict) {
        if (x <= 0) return 1;
        if (f[x] != -1) return f[x];
        for (int i = 0; i < x; ++i) {
            if (dfs(i, s, dict) == 1 && dict.count(s.substr(i, x - i)))
                return f[x] = 1;
        }
        return f[x] = 0;
    }
    vector<int> path;
    void find(int x, string s, unordered_set<string> &dict) {
        if (x <= 0) {
            int pre = s.size();
            vector<string> t;
            for (int i = 0; i < path.size(); ++i) {
                t.push_back(s.substr(path[i], pre - path[i]));
                pre = path[i];
            }
            string ans = t[t.size() - 1];
            for (int i = t.size() - 2; i >= 0; --i) ans = ans + " " + t[i];
            ret.push_back(ans);
            return;
        }
        for (int i = 0; i < x; ++i) {
            if (f[i] && dict.count(s.substr(i, x - i))) {
                path.push_back(i);
                find(i, s, dict);
                path.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        f.resize(s.size() + 1);
        for (int i = 0; i < f.size(); ++i) f[i] = -1;
        f[0] = 1;
        
        ret.clear();
        
        if (dfs(s.size(), s, dict) == 0) return ret;
        path.clear();
        find(s.size(), s, dict);
        return ret;
    }
};
