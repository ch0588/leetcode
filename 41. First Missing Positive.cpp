// Time:  O(n)
// Space: O(1)

/*
 Bucket sort
 ith element val is i+1,if not swap,O(n) time,O(1) space;
 */

class Solution {
public:
    void bucketSort(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            while (A[i] != i + 1) {
                if (A[i] < 0 || A[i] > n || A[i] == A[A[i]-1]) break;
                swap(A[i], A[A[i]-1]);
            }
        }
    }
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bucketSort(nums);
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1) return i + 1;
        return n + 1;
    }
};
