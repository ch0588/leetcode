class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();

        if(n<=1) return 0;

        int pos = 0, maxJump = nums[0], nextPos = 0;
        int ans = 0;
        while(pos+maxJump<n-1){
            nextPos = pos + maxJump;
            while(pos<nextPos){
                maxJump = max(maxJump,nums[pos]);
                maxJump--;
                pos++;
            }
            maxJump = max(maxJump,nums[pos]);
            ans++;
        }
        return ans+1;
    }
};
