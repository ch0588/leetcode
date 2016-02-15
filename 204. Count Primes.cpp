// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int countPrimes(int n) {
        bool notPrime[n + 1] = {0};
        int prime[500000], np = 0;
        notPrime[0] = notPrime[1] = true;
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (!notPrime[i]) {
                prime[np++] = i;
                res++;
            }
            for (int j = 0; j < np && prime[j] * i < n; ++j) {
                notPrime[prime[j] * i] = true;
                if (i % prime[j] == 0) break;
            }
        }
        return res;
    }
};