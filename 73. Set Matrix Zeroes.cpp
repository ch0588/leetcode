/*
use contant space, fr and fc
matrix[i][0] falg row i
matrix[0][j] falg col j
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==0) return;
        int m = matrix[0].size();
        int fr=false,fc=false;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(matrix[i][j]==0){
                    if(i==0) fr = true;
                    if(j==0) fc = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for(int i=1; i<n; ++i)
            for(int j=1; j<m; ++j)
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j] = 0;
                    
        if(fr)
            for(int j=0; j<m; ++j) matrix[0][j] = 0;
        if(fc)
            for(int i=0; i<n; ++i) matrix[i][0] = 0;
        
    }
};