/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
 */
class NumMatrix {
public:
    int **C;
    int n,m;
    NumMatrix(vector<vector<int>> &matrix) {
        n = matrix.size();
        m = n==0?0:matrix[0].size();
        C = new int*[n+1];
        for(int i=0; i<=n; ++i)
            C[i] = new int[m+1];
        
        for(int i=0; i<=n; ++i)
            for(int j=0; j<=m; ++j)
                C[i][j] = 0;
                
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j){
                int val = matrix[i][j];
                for(int p=i+1; p<=n; p+=lowbit(p))
                    for(int q=j+1; q<=m; q+=lowbit(q))
                        C[p][q] += val;
            }
    }
    
    int lowbit(int x){
        return x&(-x);
    }
    void update(int row, int col, int val) {
        int t = sumRegion(row,col,row,col);
        val = val-t;
        
        row++; col++;
        for(int i=row; i<=n; i+=lowbit(i))
            for(int j=col; j<=m; j+=lowbit(j))
                C[i][j] += val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        return sum(row2,col2)-sum(row1-1,col2)-sum(row2,col1-1)+sum(row1-1,col1-1);
    }
    
    int sum(int x,int y){
        int res = 0;
        for(int i=x; i>=1; i-=lowbit(i))
            for(int j=y; j>=1; j-=lowbit(j)){
                res += C[i][j];
            }
        return res;
        
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);