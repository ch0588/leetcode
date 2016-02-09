// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 1) return "1";
        string s = countAndSay(n - 1), res = "";
        int cnt = 1;
        char pre = s[0];
        int len = s.size();
        for (int i = 1; i < len; ++i) {
            if (s[i] == pre) cnt++;
            else {
                res += (cnt + '0');
                res += pre;
                cnt = 1;
                pre = s[i];
            }
        }
        res += (cnt + '0');
        res += pre;
        return res;
    }
};
