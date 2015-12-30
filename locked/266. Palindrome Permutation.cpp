/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?Show More Hint 
Show Company Tags
Show Tags
Show Similar Problems

 */
class Solution {
public:
    
    bool canPermutePalindrome(string s) {
        unordered_map<char,int>hash;
        for(char ch:s){
            hash[ch]++;
        }
        int odd = 0;
        for(auto h:hash){
            if(h.second&1) odd++;
        }
        if((int)s.size() % 2){
            return odd==1;
        }
        return odd==0;
    }
};