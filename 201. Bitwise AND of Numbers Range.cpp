class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        while(m!=n){
            m >>= 1;
            n >>= 1;
            res++;
        }
        return m<<res;
    }
};