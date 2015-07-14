//bi_search+hash,O(NlogN),���ֵ�m���ǻ��Ĵ����ȵ�һ�룬������ż�ֱ����ۣ�����û�е����ԡ�����abba�������ܳ���Ϊ4�Ļ��ģ����ǲ����ڳ���Ϊ3�ġ�abba���ֵ�len��2����˴���len=1��bb
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

//dp,O(N^2)��f[i][j]��ʾ[i,j]���ַ����Ƿ��ǻ��ġ���(s[i]==s[j]&&f[i+1][j-1]),f[i][j]��Ϊ�棬��ʼ����f[2][1]֮���i>j�����Ҳ��true����Ϊ���г���Ϊ�����Ļ���

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
