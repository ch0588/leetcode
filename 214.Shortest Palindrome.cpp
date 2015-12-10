/*
字符串hash
*/
class Solution {
public:
    typedef unsigned long long ll;  
    ll xp = 123;
    string shortestPalindrome(string s) {
        int n = (int)s.size();
        
        if(n<=1) return s;
        ll mi[n+2],h1[n+2],h2[n+2];
        mi[0]=1;  
        for(int i=1;i<=n;i++)  
            mi[i]=mi[i-1]*xp;  
        h1[n]=0;  
        for(int i=n-1;i>=0;i--)  
            h1[i]=h1[i+1]*xp+s[i]-'a';
        reverse(s.begin(),s.end());
        h2[n]=0;  
        for(int i=n-1;i>=0;i--)  
            h2[i]=h2[i+1]*xp+s[i]-'a';
    
        //起点为i且长len的串的哈希值  
        //h[i]-h[i+len]*mi[len];  
        
        int len;
        for(len=n; len>=2; --len){
            //n-2*len
            if( h1[0]-h1[len]*mi[len] ==  h2[n-len]-h2[n]*mi[len]) break;
        }
        
        reverse(s.begin(),s.end());
        string ret="";
        for(int i=n-1; i>=len; --i) ret+=s[i];
        ret = ret + s;
        return ret;
    }
};