// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows <= 0) return res;
        vector<int> now;
        now.push_back(1);
        res.push_back(now);
        if (numRows == 1) return res;
        
        for (int i = 1; i < numRows; ++i) {
            now.clear();
            now.push_back(1);
            for (int j = 1; j < res[i - 1].size(); ++j)
                now.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            now.push_back(1);
            res.push_back(now);
        }
        return res;
    }
};
