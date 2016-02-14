// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n <= 1) return 0;
        if (num[0] > num[1]) return 0;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid1 = (l + r) / 2;
            int mid2 = mid1 + 1;
            if (num[mid1] < num[mid2]) {
                l = mid2;
            } else {
                r = mid1;
            }
        }
        return l;
    }
    
    
};