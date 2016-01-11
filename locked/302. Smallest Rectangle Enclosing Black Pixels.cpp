/*
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.

Show Company Tags
Show Tags
 */
class Solution {
public:
    vector<vector<char>> *image;
    int minArea(vector<vector<char>> &iImage, int x, int y) {
        image = &iImage;
        int m = int(image->size()), n = int((*image)[0].size());
        int top = searchRows(0, x, 0, n, true);
        int bottom = searchRows(x + 1, m, 0, n, false);
        int left = searchColumns(0, y, top, bottom, true);
        int right = searchColumns(y + 1, n, top, bottom, false);
        return (right - left) * (bottom - top);
    }
    int searchRows(int i, int j, int low, int high, bool opt) {
        while (i != j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && (*image)[mid][k] == '0') ++k;
            if (k < high == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
    int searchColumns(int i, int j, int low, int high, bool opt) {
        while (i != j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && (*image)[k][mid] == '0') ++k;
            if (k < high == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
};


/*
https://leetcode.com/discuss/68246/c-java-python-binary-search-solution-with-explanation
Suppose we have a 2D array

"000000111000000"
"000000101000000"
"000000101100000"
"000001100100000"
Imagine we project the 2D array to the bottom axis with the rule "if a column has any black pixel it's projection is black otherwise white". The projected 1D array is

"000001111100000"
Theorem
If there are only one black pixel region, then in a projected 1D array all the black pixels are connected.
Proof by contradiction
Assume to the contrary that there are disconnected black pixels at i and j where i < j in the 1D projection array. Thus there exists one column k, k in (i, j) and and the column k in the 2D array has no black pixel. Therefore in the 2D array there exists at least 2 black pixel regions separated by column k which contradicting the condition of "only one black pixel region".
Therefore we conclude that all the black pixels in the 1D projection array is connected.
This means we can do a binary search in each half to find the boundaries, if we know one black pixel's position. And we do know that.

To find the left boundary, do the binary search in the [0, y) range and find the first column vector who has any black pixel.

To determine if a column vector has a black pixel is O(m) so the search in total is O(m log n)

We can do the same for the other boundaries. The area is then calculated by the boundaries. Thus the algorithm runs in O(m log n + n log m)
*/