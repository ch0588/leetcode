// Time Complexity: O(logn)
// Space Complexity: O(1)

/*
 十进制中只有2*5会产生0，本质是求1-N中素因子5的个数。
 
 N/5+N/5^2+N/5^3+…
 while(N){
 ret+=N/5;
 N/=5;
 }
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};