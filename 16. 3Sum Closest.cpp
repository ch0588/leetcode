// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int res = 0, diff = INT_MAX;
        int n = num.size();
        for (int i = 0; i < n - 2; ++i) {
            int t = target - num[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                if ( abs(target - (num[i] + num[l] + num[r])) < diff ){
                    diff = abs(target - (num[i] + num[l] + num[r]));
                    res = num[i] + num[l] + num[r];
                }
                if (num[l] + num[r] < t)
                    l++;
                else
                    r--;
            }
        }
        return res;
    }
};
