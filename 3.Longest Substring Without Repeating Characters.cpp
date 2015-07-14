//O(n)É¨Ò»±é
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        int h[260] = {0};
        int l=0, r=0;
        int n = (int)s.size();

        int ans = 0;
        while(r<n){
            while(r<n && h[(int)s[r]]==0){
                h[(int)s[r]]++;
                r++;
            }
            ans = max(ans,r-l);
            if(r>=n) break;
            int x = h[(int)s[r]];
            while(l<n){
                h[(int)s[l]]--;
                l++;
                if(h[x]==0) break;
            }
        }
        return ans;
    }
};
