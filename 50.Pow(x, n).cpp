/*
quickpow
n<0 and x==0
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(n==0) return 1;

        double ret = 1.0, t = x;
        bool flag = false;
        if(n<0){
            flag = true;
            n = -n;
        }
        while(n>0){
            if(n&1) ret*=t;
            n/=2;
            t*=t;
        }
        if(flag) ret = 1/ret;
        return ret;
    }
};
