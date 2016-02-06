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

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
        // Manacher's Algorithm
        string longestPalindrome(string s) {
            string T = preProcess(s);
            int n = T.length();
            vector<int> P(n);
            int C = 0, R = 0;
            for (int i = 1; i < n-1; i++) {
                int i_mirror = 2*C-i; // equals to i' = C - (i-C)

                P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

                // Attempt to expand palindrome centered at i
                while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                    P[i]++;

                // If palindrome centered at i expand past R,
                // adjust center based on expanded palindrome.
                if (i + P[i] > R) {
                    C = i;
                    R = i + P[i];
                }
            }

            // Find the maximum element in P.
            int maxLen = 0;
            int centerIndex = 0;
            for (int i = 1; i < n-1; i++) {
                if (P[i] > maxLen) {
                    maxLen = P[i];
                    centerIndex = i;
                }
            }

            return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
        }
    private:
        string preProcess(string s) {
            int n = s.length();
            if (n == 0) return "^$";
            string ret = "^";
            for (int i = 0; i < n; i++)
                ret += "#" + s.substr(i, 1);

            ret += "#$";
            return ret;
        }
};
