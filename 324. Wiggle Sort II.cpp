/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }    
        int n = nums.size();

        // Step 1: Find the median          
        vector<int>::iterator nth = next(nums.begin(), n / 2);
        nth_element(nums.begin(), nth, nums.end());
        int median = *nth;

        // Step 2: Tripartie partition within O(n)-time & O(1)-space.           
        auto m = [n](int idx) { return (2 * idx + 1) % (n | 1); };          
        int first = 0, mid = 0, last = n - 1;
        while (mid <= last) {
            if (nums[m(mid)] > median) {
                swap(nums[m(first)], nums[m(mid)]);
                ++first;
                ++mid;
            }
            else if (nums[m(mid)] < median) {
                swap(nums[m(mid)], nums[m(last)]);
                --last;
            }               
            else {
                ++mid;
            }
        }
    }    
};


Methodology:

Idea 1.

As @whnzinc pointed out in the thread https://leetcode.com/discuss/77085/clean-average-o-n-time-in-c, all elements in nums can be classified into three categories:

(1) Larger than the median;

(2) Equal to the median;

(3) Smaller than the median.

Note that it's possible to find the median within O(n)-time and O(1)-space.

Note: We can use nth_element to find the median, but it's not O(n)-time and O(1)-space. For the sake of simplicity, I might use nth_element as well.

Idea 2.

As @StefanPochmann pointed out in the thread https://leetcode.com/discuss/76965/3-lines-python-with-explanation-proof, we can arrange the elements in the three categories in a deterministic way.

(1) Elements that are larger than the median: we can put them in the first few odd slots;

(2) Elements that are smaller than the median: we can put them in the last few even slots;

(3) Elements that equal the median: we can put them in the remaining slots.

Update: According to @StefanPochmann's thread https://leetcode.com/discuss/77133/o-n-o-1-after-median-virtual-indexing), we can use a one-pass three-way partition to rearrange all elements. His idea is to re-map the indices into its destined indices, odd indices first and even indices follow.

Example:

Original Indices:    0  1  2  3  4  5  6  7  8  9 10 11
Mapped Indices:      1  3  5  7  9 11  0  2  4  6  8 10
(its reverse mapping is)

Mapped Indices:      0  1  2  3  4  5  6  7  8  9 10 11
Original Indices:    6  0  7  1  8  2  9  3 10  4 11  5   (wiggled)
In order to achieve this, we can use a function alike

int map_index(int idx, int n) {
    return (2 * idx + 1) % (n | 1);
}
where (n | 1) calculates the nearest odd that is not less than n.

Complexities: (On the condition that finding median is O(n)-time and O(1)-space)

Time: O(n)

Space: O(1)

