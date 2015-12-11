class Solution {
public:
    int countDigitOne(int n) {
        if(n<1) return 0;
        
        unsigned long long low,now,high,fac=1;
        unsigned long long ret = 0;
        while(n/fac>0){
            low = n - (n/fac)*fac;
            now = n / fac % 10;
            high = n / (fac*10);
            
            if(now == 0)
                ret += (high*fac);
            else if(now == 1)
                ret += (high*fac + low+1);
            else
                ret += ( (high+1)*fac );
            
            fac *= 10;
        }
        return ret;
    }
};