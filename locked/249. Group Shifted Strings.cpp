/*
 Given a string, we can "shift" each of its letter to its successive letter, for
 example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
 
 "abc" -> "bcd" -> ... -> "xyz"
 Given a list of strings which contains only lowercase alphabets, group all
 strings that belong to the same shifting sequence.
 
 For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
 Return:
 
 [
 ["abc","bcd","xyz"],
 ["az","ba"],
 ["acef"],
 ["a","z"]
 ]
 Note: For the return value, each inner list's elements must follow the
 lexicographic order.
 */



// Time Complexity: O(nlogn)
// Space Complexity: O(n)

class Solution {
public:
    string normalize(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int delta = s[0] - 'a';
        for (int i = 0; i < n; ++i) s[i] = (s[i] - delta + 26) % 26;
        return s;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;
        int n = strings.size();
        if (n == 0) return res;
        
        for (int i = 0; i < n; ++i) {
            string t = normalize(strings[i]);
            hash[t].emplace_back(strings[i]);
        }
        
        for (auto x : hash) {
            sort(x.second.begin(), x.second.end());
            res.emplace_back(x.second);
        }
        return res;
    }
};