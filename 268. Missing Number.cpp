class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i <= n; ++i) ans ^= (i == n) ? i : i ^ nums[i];
        return ans;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(-1);
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i && nums[i] != -1) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        int ans = -1;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == -1) {
                ans = i;
                break;
            }
        return ans;
    }
};