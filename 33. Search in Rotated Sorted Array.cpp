// Time Complexity: O(logn)
//                  O(n) if duplicates are allowed 
// Space Complexity: O(1)

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int start = 0, end = n-1;
            while (start <= end) {
                const int mid = (start + end) / 2;
                if (nums[mid] == target)
                    return mid;
                if (nums[start] <  nums[mid]) {
                    if (nums[start] <= target && target < nums[mid])
                        end = mid - 1;
                    else
                        start = mid + 1;
                } 
                else if (nums[start] > nums[mid]) {
                    if (nums[mid] < target && target <= nums[end])
                        start = mid + 1;
                    else
                        end = mid - 1;
                } 
                else
                    ++start;
            }
            return -1;
        }
};