/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

Show Company Tags
Show Tags
Show Similar Problems
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int hash[128] = {0};
        int res = 0;
        int l = 0, r = 0, n = s.size();
        int diff = 0;
        
        while(r < n) {
            if(diff <= k) {
                if(hash[s[r]]++ == 0) diff++;
                r++;
            }else {
                if(hash[s[l]]-- == 1) diff--;
                l++;
            }
            if(diff <= k) res = max(res, r - l);
        }
        return res;
        
        
        
    }
};