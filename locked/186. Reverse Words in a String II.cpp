/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array
 */

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        for (int i = 0, j = 0; i < n; i = j + 1) {
            j = i;
            while (j < n && !isblank(s[j])) j++;
            reverse(s.begin() + i, s.begin() + j);
        }
    }
};