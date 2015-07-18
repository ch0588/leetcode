class Solution {
public:
    string countAndSay(int n) {
        if(n<=1) return "1";
        string s = countAndSay(n-1), ret = "";
        int cnt = 1;
        char pre = s[0];
        for(int i=1; i<(int)s.size(); ++i){
            if(s[i] == pre) cnt++;
            else{
                ret += (cnt+'0');
                ret += pre;
                cnt = 1;
                pre = s[i];
            }
        }
        ret += (cnt+'0');
        ret += pre;
        return ret;
    }
};
