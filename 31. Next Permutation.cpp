// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int p = -1;

        //from end,find first increase,nums[p]<nums[p+1]
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                p = i;
                break;
            }
        }
        if (p == -1) { // all increase
            sort(nums.begin(),nums.end());
            return;
        }

        //find the min value at nums[pos] which bigger than nums[p]
        //have the same value,get the rightest
        int value = nums[p+1], pos = p+1;
        for (int i = p + 2; i < n; ++i){
            if (nums[i] > nums[p] && nums[i] <= value) {
                value = nums[i];
                pos = i;
            }
        }

        swap(nums[p], nums[pos]);

        //reverse [p+1,end)
        int l = p + 1, r = n - 1;
        while (l <= r) {
            swap(nums[l], nums[r]);
            l++; r--;
        }
    }
    //5 2 4 3 1
    //5 3 1 2 4

    //[2,3,1,3,3]
    //[2,3,3,1,3]

    //http://jingyan.baidu.com/article/63acb44a90370061fcc17e18.html
};
