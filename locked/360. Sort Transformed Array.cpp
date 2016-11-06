/*
Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (nums.empty()) return vector<int>();
        
        vector<int> res(nums.size(), 0);
        if (a!=0) {
            double mid = -(double)b/(2*(double)a);
            int head = 0, tail = nums.size()-1, idx = 0, x = 0;
            while (head<=tail) {
                if (abs((double)nums[head]-mid)<=
                    abs((double)nums[tail]-mid)) {
                    x = nums[tail]; --tail;
                } else {
                    x = nums[head]; ++head;
                }
                res[idx++] = a*x*x+b*x+c;
            }
        } else {
            for (int i=0; i<nums.size(); ++i) res[i] = b*nums[i]+c;
        }
        
        if (a>0 || (a==0 && b<0)) reverse(res.begin(), res.end());
        return res;
    }
};

