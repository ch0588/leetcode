// Time Complexity: O(n+m)
// Space Complexity: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = m + n - 1;
        int ida = m - 1, idb = n - 1;
        while (ida >= 0 && idb >= 0) {
            if (nums1[ida] > nums2[idb]) {
                nums1[cur--] = nums1[ida--];
            } else {
                nums1[cur--] = nums2[idb--];
            }
        }
        while (ida >= 0) {
            nums1[cur--] = nums1[ida--];
        }
        while (idb >= 0) {
            nums1[cur--] = nums2[idb--];
        }
    }
};