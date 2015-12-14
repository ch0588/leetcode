class Solution {
public:
    int titleToNumber(string s) {
        int base = 1,res = 0;
        for(int i=(int)s.size()-1; i>=0; --i){
            res += (s[i]-'A'+1)*base;
            base*=26;
        }
        return res;
    }
};

//related to
class Solution {
public:
    string convertToTitle(int n) {
        if(n<=0) return "NULL";
        string s;
        while(n>0){
            n--;
            s+=(n%26+'A');
            n/=26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};