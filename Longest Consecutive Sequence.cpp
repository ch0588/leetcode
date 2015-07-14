class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,int>H;
        H.clear();
        int n = (int)num.size();
        for(int i=0; i<n; ++i) H[ num[i] ] = 1;

        int ans = 0;
        for(int i=0; i<n; ++i){
            if(H[num[i]]==-1) continue;

            int l = 0, t=1;
            while( H.find(num[i]-t)!=H.end() ) {
                H[num[i]-t] = -1;
                l++; t++;
            }
            int r = 0;
            t=1;
            while( H.find(num[i]+t)!=H.end() ) {
                H[num[i]+t] = -1;
                r++; t++;
            }
            //printf("%d %d %d\n",i,l,r);
            ans = max(ans,r+l+1);
        }
        return ans;

    }
};
