// Time Complexity: O(2^n)
// Space Complexity: O(1)

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int n = S.size();
        int sumStates = 1 << n;
        sort(S.begin(), S.end());
        vector<vector<int> > res;
        for (int i = 0; i < sumStates; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j)
                if ((i >> j) & 1) temp.push_back(S[j]);
            res.emplace_back(temp);
        }
        return res;
    }
};
