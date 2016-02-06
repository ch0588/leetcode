/*
x<0
x<INT_MIN || x>INT_MAX
*/
class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x<0) {
            sign = -1;
            x = -x;
        }
        long long ans = 0;
        while(x){
            ans = ans*10LL + x%10;
            x/=10;
        }
        ans*=sign;
        if(ans>INT_MAX) return 0;
        if(ans<INT_MIN) return 0;
        return ans;
    }
};
