// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> values;
        string tmp = "";
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ')
                values.push_back(tmp), tmp = "";
            else
                tmp += str[i];
        }
        values.push_back(tmp);
        
        int n = values.size();
        if (n != (int)pattern.size()) return false;
        
        map<char, int> p2v;
        map<string, int> v2p;
        for (int i = 0; i < n; ++i) {
            if (p2v[pattern[i]] != v2p[values[i]]) return false;
            p2v[pattern[i]] = v2p[values[i]] = i + 1;
        }
        return true;
    }
    
    
};