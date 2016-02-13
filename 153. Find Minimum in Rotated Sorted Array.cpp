// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int> &num) {
        int ans = num[0];
        int l = 0, r = (int)num.size() - 1, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            ans = min(ans, num[m]);
            if (num[l] > num[r]) {  // rot
                if (num[m] >= num[l])
                    l = m + 1;
                else
                    r = m - 1;
            } else {  // sort
                r = m - 1;
            }
        }
        return ans;
    }
};
