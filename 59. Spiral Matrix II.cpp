// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));
        int begin = 0, end = n - 1;
        int id = 1;
        while (begin < end) {
            for (int i = begin; i < end; ++i) res[begin][i] = id++;
            for (int i = begin; i < end; ++i) res[i][end] = id++;
            for (int i = end; i > begin; --i) res[end][i] = id++;
            for (int i = end; i > begin; --i) res[i][begin] = id++;
            begin++; end--;
        }
        if (begin == end) res[begin][end] = id++;
        
        return res;
    }
};
