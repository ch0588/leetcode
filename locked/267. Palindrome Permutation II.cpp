/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].

Hint:

If a palindromic permutation exists, we just need to generate the first half of the string.Show More Hint 
Show Tags
Show Similar Problems

 */
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        if (s.empty()) {
            return {};
        }
        
        unordered_map<char, int> cnt;
        for (const auto &c : s) {
            ++cnt[c];
        }
        
        string mid, chars;
        for (const auto &kvp : cnt) {
            if (kvp.second % 2) {
                if (mid.empty()) {
                    mid.push_back(kvp.first);
                } else {  // The count of the middle char is at most one.
                    return {};
                }
            }
            chars.append(kvp.second / 2, kvp.first);
        }
        return permuteUnique(mid, chars);
    }
    
    vector<string> permuteUnique(const string &mid, string &chars) {
        vector<string> result;
        sort(chars.begin(), chars.end());
        do {
            string reverse_chars(chars.crbegin(), chars.crend());
            result.emplace_back(chars + mid + reverse_chars);
        } while (next_permutation(chars.begin(), chars.end()));
        return result;
    }
};

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> result;
        unordered_map<char, int> charCount;
        int oddCnt=0, N=0;
        string mid;
        for (int i=0; i<s.size(); i++)
            charCount[s[i]] ++;
        for (auto &c : charCount) {
            if (c.second & 1) {
                mid = c.first;
                oddCnt++;
            }
            c.second /= 2;
            N += c.second;
        }
        if (oddCnt > 1)
            return result;
        helper(charCount, "", mid, N, result);
        return result;
    }
private:
    void helper(unordered_map<char, int> &charCount, string s, string &mid, int &N, vector<string> &r) {
        if (s.size() == N) {
            string rev = s;
            reverse(rev.begin(), rev.end());
            r.push_back(s + mid + rev);
            return;
        }
        for (auto &c : charCount) {
            if (c.second > 0) {
                c.second--;
                helper(charCount, s+c.first, mid, N, r);
                c.second++;
            }
        }
    }
};