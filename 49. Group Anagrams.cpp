// Time Complexity: O(klogk * n) ~= O(n), k is length of string, n is number of strings
// Space Complexity: O(k * n) ~= O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > H;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            H[t].push_back(s);
        }
        vector<vector<string>> res;
        
        for (auto it = H.begin(); it != H.end(); it++) {
            sort(it->second.begin(), it->second.end());
            res.emplace_back(it->second);
        }
        return res;
    }
};