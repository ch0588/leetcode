class Solution {
public:
    void update(string &s,int pos, int val) {
        int r = val;
        while (r > 0) {
            if (pos >= (int)s.size()) s += "0";
            r += (s[pos]-'0');
            s[pos] = r % 10 + '0';
            r = (r - r % 10) / 10;
            pos++;
        }
    }
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int l1 = (int)num1.size();
        int l2 = (int)num2.size();
        string res = "";
        for (int i = 0; i <= l1 + l2; ++i) res += "0";
        
        for (int i = 0; i < l1; ++i)
            for (int j = 0; j < l2; ++j)
                update(res, i+j, (num1[i] - '0') * (num2[j] - '0'));
        
        string ans = "";
        int i = (int)res.size()-1;
        while (res[i] == '0') i--;
        for (int j = i; j >= 0; --j) ans += res[j];
        if((int)ans.size() == 0) ans = "0";
        return ans;
    }
};
