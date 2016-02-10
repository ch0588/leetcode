// Time Complexity: O(n^m), where n is max length of number, m is count of segment
// Space Complexity: O(nm)

class Solution {
public:
    vector<string> res;
    vector<string> path;
    void dfs(int pos, string s) {
        if (pos == (int)s.size() && (int)path.size() == 4) {
            string ans = path[0];
            for (int i = 1; i < 4; ++i) ans = ans + '.' + path[i];
            res.push_back(ans);
            return;
        }
        if ((int)path.size() >= 4) return;
        if (pos >= (int)s.size()) return;
        
        int x = 0;
        string t = "";
        for (int i = pos; i < pos + 3 && i < (int)s.size(); ++i) {
            x = 10 * x + s[i] - '0';
            t += s[i];
            if ((i == pos + 1 && x < 10) || (i == pos + 2 && x < 100))
                break;  // 0.1.0.010 or 0.100.10 not valid
            if (x >= 0 && x <= 255) {
                path.push_back(t);
                dfs(i + 1, s);
                path.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        path.clear();
        dfs(0, s);
        return res;
    }
};
