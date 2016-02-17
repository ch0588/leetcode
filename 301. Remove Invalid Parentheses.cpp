/*
 calc the dest string len first(removedLeft,removedRight);
 s: source sring
 len: s.length
 cur: current searching string
 pos: search pos in s
 rl: need remove left num
 rr: need remove right num
 ol: opened left until pos
 
 rn: the right nums from right to left,cut branch
 */
class Solution {
public:
    vector<string> res;
    unordered_set<string> hash;
    vector<int> rn;
    void dfs(string &s, int len, string cur, int pos, int rl, int rr, int ol) {
        if (rl == 0 && rr == 0 && ol == 0 && pos == len) {
            if (hash.find(cur) == hash.end()) {  // hash
                hash.insert(cur);
                res.push_back(cur);
            }
            return;
        }
        if (pos >= len) return;
        
        if (rn[pos] < ol)
            return;  // cut branch, not matched left > reamin right num
        
        if (s[pos] == '(') {
            dfs(s, len, cur + "(", pos + 1, rl, rr, ol + 1);  // don't remove this
            // left
            if (rl > 0) dfs(s, len, cur, pos + 1, rl - 1, rr, ol);  // remove this
            // left
        } else if (s[pos] == ')') {
            if (ol > 0)
                dfs(s, len, cur + ")", pos + 1, rl, rr,
                    ol - 1);  // don't remove this right
            if (rr > 0)
                dfs(s, len, cur, pos + 1, rl, rr - 1, ol);  // remove this right
        } else {
            dfs(s, len, cur + s[pos], pos + 1, rl, rr, ol);  // other string
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        res.clear();
        hash.clear();
        int n = s.size();
        
        rn.reserve(n + 1);
        rn[n] = 0;
        for (int i = n - 1; i >= 0; --i) rn[i] = rn[i + 1] + (s[i] == ')' ? 1 : 0);
        
        int removedRight = 0;
        int openLeft = 0;
        for (auto c : s) {
            if (c == '(')
                openLeft++;
            else if (c == ')') {
                if (openLeft > 0)
                    openLeft--;
                else
                    removedRight++;
            }
        }
        dfs(s, (int)s.size(), "", 0, openLeft, removedRight, 0);
        return res;
    }
};