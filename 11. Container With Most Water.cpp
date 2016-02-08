/*
Start by evaluating the widest container, using the first and the last line. All other possible containers are less wide, so to hold more water, they need to be higher. Thus, after evaluating that widest container, skip lines at both ends that don't support a higher height. Then evaluate that new container we arrived at. Repeat until there are no more possible containers left.
*/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        int l = 0, r = n-  1;
        int ret = 0;
        while (l < r) {
            ret = max( ret, (r - l) * min(height[l], height[r]) );
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ret;
    }
};
