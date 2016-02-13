// Time Complexity: O(1)
// Space Complexity: O(n)

class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() == 0) return 0;
        int ans = num[0];
        for (int i = 1; i < num.size(); ++i) ans = min(ans, num[i]);
        return ans;
    }
};
