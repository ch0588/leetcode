/*
Given two strings S and T, determine if they are both one edit distance apart.
*/


// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n > m) swap(s, t);
        // n<=m
        if (m - n > 1) return false;
        
        if (n == m) {
            int diff = 0;
            for (int i = 0; i < n; ++i)
                if (s[i] != t[i]) diff++;
            return diff == 1;
        } else {
            int i = 0, diff = 0;
            
            while (i < n) {
                if (s[i] != t[i + diff]) {
                    diff++;
                    if (diff > 1) break;
                } else {
                    i++;
                }
            }
            return diff <= 1;
        }
    }
};