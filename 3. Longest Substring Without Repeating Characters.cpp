class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int start = 0, res = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (last[s[i]] >= start) {  // meet a repeated character
                res = max(res, i - start);  // recount max length of substring
                start = last[s[i]] + 1; // update start index next to the repeated one
            } 
            last[s[i]] = i; // update last index
        }
        res = max(res, len - start);    // recount max length of substring due to end
        return res;
    }
};