class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n));
        int begin = 0, end = n-1;
        int id = 1;
        while(begin<end){
            for(int i=begin; i<end; ++i) ans[begin][i] = id++;
            for(int i=begin; i<end; ++i) ans[i][end] = id++;
            for(int i=end; i>begin; --i) ans[end][i] = id++;
            for(int i=end; i>begin; --i) ans[i][begin] = id++;
            begin++; end--;
        }
        if(begin==end) ans[begin][end] = id++;

        return ans;
    }
};
