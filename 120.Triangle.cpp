class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int>ret = triangle.back();
        for(int i=triangle.size()-2; i>=0; --i)
            for(int j=0; j<=i; ++j)
                ret[j] = triangle[i][j] + min(ret[j],ret[j+1]);
        return ret[0];
    }
};