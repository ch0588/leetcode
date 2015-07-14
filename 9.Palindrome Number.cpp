/*
O(1) extra space
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return 0;
        }
        int p = x, q = 0;
        while(p) {
            q = q * 10 + p % 10;
            p /= 10;
        }
        return q == x;
    }
};
