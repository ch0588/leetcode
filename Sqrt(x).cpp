class Solution {
public:
    int sqrt(int x) {
        if(x<1) return 0;
        long long ans = static_cast<long long>(x);
        long long l=1LL,r=x,m;
        while(l<=r){
            m = (l+r)/2LL;
            if(m*m<=x){
                ans = m;
                l = m+1LL;
            }
            else{
                r = m-1LL;
            }
        }
        return ans;
    }
};
