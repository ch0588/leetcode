// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        int l = 0, r = n - 1, u = 0, d = m - 1;
        while (l < r && u < d) {
            for (int i = l; i < r; ++i) res.emplace_back(matrix[u][i]);
            for (int i = u; i < d; ++i) res.emplace_back(matrix[i][r]);
            for (int i = r; i > l; --i) res.emplace_back(matrix[d][i]);
            for (int i = d; i > u; --i) res.emplace_back(matrix[i][l]);
            l++; r--;
            u++; d--;
        }
        if (l < r && u == d) {
            for (int i = l; i <= r; ++i) res.emplace_back(matrix[u][i]);
        }
        if (u < d && l == r) {
            for (int i = u; i <= d; ++i) res.emplace_back(matrix[i][l]);
        }
        if (l == r && u == d) res.emplace_back(matrix[u][l]);
        return res;
    }
};
