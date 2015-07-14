class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==0) return 0;
        int ans = A[0];
        int t =0 ;
        for(int i=0; i<n; ++i){
            t+=A[i];
            ans = max(ans,t);
            if(t<0) t=0;
        }
        return ans;
    }
};
