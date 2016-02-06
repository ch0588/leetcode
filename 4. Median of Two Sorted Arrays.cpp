class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if ((m + n) % 2 == 1) { //odd
            return findKthInTwoSortedArrays((m+n+1) / 2, nums1.begin(), m, nums2.begin(), n);
        } else {
            return ( findKthInTwoSortedArrays((m+n) / 2, nums1.begin(), m, nums2.begin(), n)
                   + findKthInTwoSortedArrays((m+n) / 2 + 1, nums1.begin(), m, nums2.begin(), n) ) / 2.0;
        }
    }
private:
    double findKthInTwoSortedArrays(int k, vector<int>::iterator it1, int m, vector<int>::iterator it2, int n) {
        if (m > n) return findKthInTwoSortedArrays(k, it2, n, it1, m);
        if (m == 0) return *(it2 + k - 1);
        if (k == 1) return min(*it1, *it2);
        int pa = min(k / 2, m);
        int pb = k - pa;
        if (*(it1 + pa - 1) < *(it2 + pb -1)) return findKthInTwoSortedArrays(k - pa, it1+pa, m - pa, it2, n);
        else if (*(it1 + pa - 1) > *(it2 + pb -1)) return findKthInTwoSortedArrays(k - pb, it1, m, it2 + pb, n - pb);
        else return *(it1 + pa - 1);
    }
};