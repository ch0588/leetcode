// Time:  O(n!)
// Space: O(1)

class Solution {
public:
    bool nextPermutation(vector<int>& nums) {
        int p = -1;
        //from end,find first increase,nums[p]<nums[p+1]
        for (int i = (int)nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                p = i;
                break;
            }
        }
        if (p == -1) { // all decrease
            sort(nums.begin(), nums.end());
            return false;
        }
        
        //find the min value at nums[pos] which bigger than nums[p]
        int value = nums[p + 1], pos = p + 1;
        for (int i = p + 2; i < nums.size(); ++i) {
            if (nums[i] > nums[p] && nums[i] <= value){
                value = nums[i];
                pos = i;
            }
        }
        
        swap(nums[p],nums[pos]);
        
        //reverse [p+1,end)
        int l = p + 1, r = (int)nums.size() - 1;
        while (l <= r) {
            swap(nums[l], nums[r]);
            l++; r--;
        }
        return true;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (nextPermutation(nums));
        return res;
    }
};
