// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        return !(n & (n - 1));
    }
};