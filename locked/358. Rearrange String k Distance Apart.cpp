/*
Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
str = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
Example 3:
str = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.
*/

class Node {
public:
    char ch;
    int cnt;
    Node(char _ch, int _cnt) : ch(_ch), cnt(_cnt) {}
};

class Cmp {
public:
    bool operator()(Node a, Node b) {
        if (a.cnt == b.cnt) return a.ch > b.ch;
        return a.cnt < b.cnt;
    }
};


class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k <= 1) return str;
        priority_queue<Node, vector<Node>, Cmp> Q;
        unordered_map<char, int> H;
        int len = str.length();
        
        for (auto ch : str) H[ch]++;
        for (auto it : H)   Q.push(Node(it.first, it.second));

        
        string res = "";
        while (!Q.empty()) {
            // cout<<Q.size()<<endl;
            vector<Node>tmp;
            int n = min(k, len);
            for (int i = 0; i < n; ++i) {
                if (Q.empty()) return "";
                Node t = Q.top();
                Q.pop();
                t.cnt--;
                if (t.cnt > 0)
                    tmp.push_back(t);
                res += t.ch;
                len--;
            }
            for (auto it : tmp) Q.push(it);
        }
        return res;
    }
};

