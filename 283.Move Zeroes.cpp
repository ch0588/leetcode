class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, n = nums.size();
        for(auto x:nums)
            if(x) nums[l++] = x;
        for(int i=l; i<n; ++i) nums[i] = 0;
    }
};