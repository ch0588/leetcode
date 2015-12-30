Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int len = words.size();
        int n = 3*len, m = -3*len;
        int res = len+1;
        for(int i=0; i<len; ++i){
            if(words[i]==word1) n=i;
            else if(words[i]==word2) m=i;
            res = min(res,abs(n-m));
        }
        return res>len?INT_MAX:res;
    }
};