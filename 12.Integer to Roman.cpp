class Solution {
public:
    string intToRoman(int num) {
        const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans="";
        int i = 0;
        while(i<13&&num>0){
            int cnt = num/radix[i];
            num %= radix[i];
            while(cnt--) ans+=symbol[i];
            i++;
        }
        return ans;
    }
};
