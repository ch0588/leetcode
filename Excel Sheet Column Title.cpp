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
