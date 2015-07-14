//bi_search+hash,O(NlogN),二分的m，是回文串长度的一半，按照奇偶分别讨论，否则没有单调性。例如abba，存在总长度为4的回文，但是不存在长度为3的。abba二分的len是2，因此存在len=1的bb
class Solution {
public:
    const int P = 123;
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0) return "";

        unsigned long long H[1010],xp[1010],HF[1010];
        H[n] = 0;
        for(int i=n-1; i>=0; --i) H[i] = H[i+1]*P+(s[i]-'a');
        HF[n] = 0;
        for(int i=n-1; i>=0; --i) HF[i] = HF[i+1]*P+(s[n-i-1]-'a');

        xp[0] = 1;
        for(int i=1; i<=n; ++i) xp[i] = xp[i-1]*P;

        int maxLen=1,maxPos=0;

        int l=0, r=n, m;
        while(l<=r) {
            m = (l+r)/2;
            bool flag = false;
            int len;
            for(int i=0; i+2*m-1<n; ++i) {
                len = 2*m;
                if( H[i]-H[i+len]*xp[len] == HF[n-i-len]-HF[n-i]*xp[len] ) {
                    flag = true;
                    if(maxLen<len) {
                        maxLen=len;
                        maxPos = i;
                    }
                }
                len = 2*m+1;
                if( i+2*m<n && H[i]-H[i+len]*xp[len] == HF[n-i-len]-HF[n-i]*xp[len] ) {
                    flag = true;
                    if(maxLen<len) {
                        maxLen=len;
                        maxPos = i;
                    }
                }
            }
            if(flag) l=m+1;
            else    r=m-1;
        }
        return s.substr(maxPos,maxLen);
    }
};

//dp,O(N^2)，f[i][j]表示[i,j]的字符串是否是回文。当(s[i]==s[j]&&f[i+1][j-1]),f[i][j]才为真，初始化是f[2][1]之类的i>j的情况也是true，因为会有长度为奇数的回文

class Solution {
public:
    int f[1005][1005];
    char s[1010];
    int maxLen,maxPos;
    int dfs(int i,int j) {
        if(f[i][j]!=-1) return f[i][j];

        if(i>=j)    return f[i][j] = 1;

        if(s[i]==s[j]&&dfs(i+1,j-1)) {
            if(maxLen<j-i+1){
                maxLen = j-i+1;
                maxPos = i;
            }
            return f[i][j] = 1;
        }
        return f[i][j] = 0;
    }

    string longestPalindrome(string str) {
        int n = (int)str.size();
        if(n==0) return "";

        for(int i=0; i<n; ++i) s[i]=str[i];
        s[n]='\0';
        maxLen = 1, maxPos = 0;
        memset(f,-1,sizeof(f));
        for(int i=0; i<n; ++i)
            for(int j=i; j<n; ++j){
                f[i][j] = dfs(i,j);
            }
        return str.substr(maxPos,maxLen);
    }
};
