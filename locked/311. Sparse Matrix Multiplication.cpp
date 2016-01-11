/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
 */

// Time:  O(m * n * l), A is m x n matrix, B is n x l matrix
// Space: O(m * l)

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int m = A.size(), n = A[0].size(), l = B[0].size();
        vector<vector<int>> res(m, vector<int>(l));
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < n; ++k) {
                if (A[i][k]) {
                    for (int j = 0; j < l; ++j) {
                        res[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int p = B.size();
        int n = B[0].size();
        vector<vector<int>> C(m, vector<int>(n));
        unordered_map<int, unordered_map<int, int>> sA;
        unordered_map<int, unordered_map<int, int>> sB;
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < p; k++) {
                if (A[i][k] != 0)
                    sA[i][k] = A[i][k];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                if (B[k][j] != 0)
                    sB[j][k] = B[k][j];
            }
        }
        int row, col;
        for (auto iA = sA.begin(); iA != sA.end(); iA++) {
            auto rA = iA->second;
            for (auto iB = sB.begin(); iB != sB.end(); iB++) {
                auto cB = iB->second;
                for (auto iter = rA.begin(); iter != rA.end(); iter++) {
                    if (cB.find(iter->first) != cB.end()) {
                        C[iA->first][iB->first] += iter->second * cB[iter->first];
                    }
                }
            }
        }
        return C;
    }
};