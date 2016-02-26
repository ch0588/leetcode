/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int hash[128] = {0};
        int n = s.size();
        if (n == 0) return 0;
        
        int res = 0;
        int l = 0, r = 0;
        int diff = 0;
        while (r < n) {
            while (r < n && diff <= 2) {
                int x = s[r];
                hash[x]++;
                if (hash[x] == 1) diff++;
                if (diff <= 2) res = max(res, r - l + 1);
                r++;
            }
            while (l <= r && diff > 2) {
                int x = s[l];
                hash[x]--;
                if (hash[x] == 0) diff--;
                l++;
            }
        }
        return res;
    }
};