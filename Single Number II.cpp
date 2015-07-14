class Solution {
public:
    int singleNumber(int A[], int n) {
        int cnt[65] = {0};
        for(int i=0; i<n; ++i)
            for(int j=0; j<32; ++j){
                cnt[j] += ( (A[i]>>j)&1 );
                cnt[j] %= 3;
            }

        int ans = 0;
        for(int i=0; i<32; ++i)
            if( cnt[i]!=0 ) ans+=( (1<<i)*cnt[i] );

        return ans;
    }
};
