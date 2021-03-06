/*
I V X   L   C    D    M
1 5 10  50  100  500  1000
*/
class Solution {
public:
    int romanToInt(string s) {
        const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int res = 0;
        map<string,int>h;
        for (int i = 0; i < 13; ++i)    h[ symbol[i] ] = radix[i];
        
        int pos = 0;
        for (int i = 0; i < 13; ++i) {
            while (pos + (int)symbol[i].size() <= (int)s.size() && s.substr(pos, (int)symbol[i].size()) == symbol[i]) {
                res += radix[i];
                pos += (int)symbol[i].size();
            }
        }
        return res;
    }
};
