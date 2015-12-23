class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0) return false;
        int m = matrix[0].size();
        if(m==0) return false;
        int r = 0;
        while(r<n && m>=1 ){
            if(matrix[r][m-1]==target) return true;
            else if(matrix[r][m-1]>target) m--;
            else r++;
        }
        return false;
    }
};