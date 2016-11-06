/*
Given a rows x cols screen and a sentence represented by a list of words, find how many times the given sentence can be fitted on the screen.

Note:

A word cannot be split into two lines.
The order of words in the sentence must remain unchanged.
Two consecutive words in a line must be separated by a single space.
Total words in the sentence won't exceed 100.
Length of each word won't exceed 10.
1 ≤ rows, cols ≤ 20,000.
Example 1:

Input:
rows = 2, cols = 8, sentence = ["hello", "world"]

Output: 
1

Explanation:
hello---
world---

The character '-' signifies an empty space on the screen.
Example 2:

Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]

Output: 
2

Explanation:
a-bcd- 
e-a---
bcd-e-

The character '-' signifies an empty space on the screen.
Example 3:

Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]

Output: 
1

Explanation:
I-had
apple
pie-I
had--

The character '-' signifies an empty space on the screen.
*/

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        int cnt[n] = {0}, next[n];
        for (int i = 0; i < n; ++i) {
            int cur = 0, index = i;
            bool first = true;
            while (cur + sentence[index].length() + (first == false) <= cols) {
                cur += sentence[index].length() + (first == false);
                first = false;
                index = (index + 1) % n;
                if (index == 0) cnt[i]++;
            }
            next[i] = index;
        }
        
        int res = 0;
        int index = 0;
        while (rows--) {
            res += cnt[index];
            index = next[index];
        }
        return res;
    }
};

