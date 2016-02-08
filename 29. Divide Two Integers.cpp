// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
    public:
        int divide(int dividend, int divisor) {
            long long a = dividend >= 0 ? dividend : -(long long)dividend;
            long long b = divisor >= 0 ? divisor : -(long long)divisor;
        
            cout<<a<<"\t"<<b<<endl;
            
            long long result = 0;
            while(a >= b) {
                long long c = b;
                int i = 0;
                for(; a >= c; c <<= 1, ++i);
                if(i > 0) {
                    a -= c >> 1;
                    result += 1LL << (i - 1);
                }
            }

            long long res = ((dividend ^ divisor) >> 31)? -result : result;
            if (res < (long long)INT_MIN || res > (long long)INT_MAX) return INT_MAX;
            return res;
        }
};