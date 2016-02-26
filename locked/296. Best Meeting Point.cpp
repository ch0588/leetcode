/*
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

Show Hint 
Try to solve it in one dimension first. How can this solution apply to the two dimension case?

Show Tags
Show Similar Problems

 */

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        int C[n * m];
        int res = 0;
        for (int dim = 0; dim < 2; ++dim) {
            int k = 0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (grid[i][j] == 1) {
                        C[k++] = dim ? j : i;
                    }
            nth_element(C, C + k / 2, C + k);
            int median = C[k / 2];
            for (int i = 0; i < k; ++i) res += (abs(median - C[i]));
        }
        return res;
    }
};