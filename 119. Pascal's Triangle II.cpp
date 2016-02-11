// Time Complexity: O(k)
// Space Complexity: O(1)

/*
 http://blog.csdn.net/perfumekristy/article/details/8713083
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 0; i <= rowIndex; ++i) {
            long long sum = 1;
            for (int j = 1; j <= i; j++) {
                sum = sum * (rowIndex - i + j) / j;
            }
            res.push_back((int)sum);
        }
        return res;
    }
};
