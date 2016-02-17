// https://leetcode.com/discuss/69424/clean-c-solution-and-explaination-o-mn-space-with-o-1-time
class NumMatrix {
private:
    int row, col;
    vector<vector<int>> sums;
    
public:
    NumMatrix(vector<vector<int>> &matrix) {
        row = matrix.size();
        col = row > 0 ? matrix[0].size() : 0;
        sums = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                sums[i][j] = matrix[i - 1][j - 1] + sums[i - 1][j] + sums[i][j - 1] -
                sums[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] -
        sums[row1][col2 + 1] + sums[row1][col1];
    }
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);