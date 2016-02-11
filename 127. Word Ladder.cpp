// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    struct NODE {
        string s;
        int t;
        NODE(){};
        NODE(string _s, int _t) {
            s = _s;
            t = _t;
        }
    };
    
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start.size() != end.size()) return 0;
        unordered_set<string> H;
        H.clear();
        
        NODE now, next;
        queue<NODE> Q;
        
        now = NODE(start, 1);
        Q.push(now);
        H.insert(now.s);
        while (!Q.empty()) {
            now = Q.front();
            Q.pop();
            if (now.s == end) return now.t;
            
            next.t = now.t + 1;
            for (int i = 0; i < now.s.size(); ++i)
                for (int j = 0; j < 26; ++j) {
                    next.s = now.s;
                    next.s[i] = 'a' + j;
                    if (H.count(next.s)) continue;
                    if (!dict.count(next.s)) continue;
                    H.insert(next.s);
                    Q.push(next);
                }
        }
        return 0;
    }
};
