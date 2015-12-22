class Solution {
public:
    int getRectangle(vector<int>&height){
        int n = height.size();
        int res = 0, i = 0;
        stack<int>index;
        while(i<n){
            while(!index.empty() && height[index.top()]>=height[i]){
                int h = height[index.top()];
                index.pop();
                int idx = index.empty()?-1:index.top();
                res = max(res,(i-idx-1)*h);
            }
            index.push(i++);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row==0) return 0;
        int n = matrix[0].size();
        vector<int>height;
        for(int i=0; i<n; ++i) height.push_back(matrix[0][i]-'0');
        height.push_back(0);
        int res = 0;
        for(int r=1; r<row; ++r){
            res = max(res,getRectangle(height));
            for(int i=0; i<n; ++i){
                if(matrix[r][i]=='1') height[i]++;
                else height[i] = 0;
            }
        }
        res = max(res,getRectangle(height));
        return res;
    }
};