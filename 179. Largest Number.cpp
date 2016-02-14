// Time Complexity: O(logn)
// Space Complexity: O(n)

/*
 121 12 | 12111 12121
 128 12 | 12812 12128
 */
class Solution {
public:
    static bool cmp(string a, string b) {
        string c = a + b;
        string d = b + a;
        return c < d;
    }
    string largestNumber(vector<int> &num) {
        vector<string> str;
        for (int i = 0; i < num.size(); ++i) {
            str.push_back(to_string(num[i]));
        }
        sort(str.begin(), str.end(), cmp);
        string res = "";
        for (int i = (int)str.size() - 1; i >= 0; --i) res += str[i];
        
        bool not0 = false;
        for (int i = 0; i < res.size(); ++i)
            if (res[i] != '0') not0 = true;
        if (not0 == false)
            return "0";
        else
            return res;
    }
};
