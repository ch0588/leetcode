/*
Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":

Return false.
*/

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int lenw = word.length(), lena = abbr.length();
        int i = 0, j = 0;
        while(i < lena) {
            if (abbr[i] >= 'a' && abbr[i] <= 'z') {
                // cout<<"i:"<<i<<"\tj:"<<j<<endl;
                if (j >= lenw || word[j] != abbr[i]) return false;
                i++, j++;
            } else {
                int cur = 0;
                while (i < lena && abbr[i] >= '0' && abbr[i] <= '9') {
                    cur = 10 * cur + (abbr[i++] - '0');
                    if (cur == 0) return false;
                }
                // cout<<"i:"<<i<<"\tcur:"<<cur<<endl;
                j += cur; 
                if (j > lenw) return false;
            }
        }
        return (i == lena && j == lenw);
    }
};

