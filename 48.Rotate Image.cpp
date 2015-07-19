//from outer to inner
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        for(int i=0; i<n/2; ++i){
            for(int j=i; j<n-i-1; ++j){
                int t = matrix[i][j];
                int x=i,y=j;
                for(int k=0; k<3; ++k){
                    int nx = n-y-1,ny = x;
                    matrix[x][y] = matrix[nx][ny];
                    x = nx; y = ny;
                }
                matrix[x][y] = t;
            }
        }
    }
};
