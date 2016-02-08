// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> >res;
        res.clear();
        sort(num.begin(), num.end());
        int n = num.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && num[i] == num[i-1]) continue; //Skip duplicated.
            int l = i + 1, r = n - 1;
            int target = -1 * num[i]; //hash second item
            int prel = num[i] - 1; 
            while (l < r) {
                if (num[l] + num[r] == target) {
                    if(num[l] != prel) {
                        vector<int>t;
                        prel = num[l];
                        res.push_back({num[i], num[l], num[r]});
                    }
                    l++; r--;
                } else if (num[l] + num[r] < target) l++;
                else r--;
            }
        }
        return res;
    }
};
