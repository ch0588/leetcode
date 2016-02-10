// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, c = 0;
        string s;
        
        while (i >= 0 || j >= 0 || c) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c >>= 1;
        }
        return s;
    }
};