// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int last_end = n-1;
        while (s[last_end] == ' ' && last_end >= 0) last_end--;
        int res = 0;
        while (s[last_end] != ' ' && last_end >= 0) res++,last_end--;
        
        return res;
    }
};
