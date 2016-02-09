// Time Complexity: O(n)
// Space Complexity: O(1)
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


// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int last = 0;
        int cur = 0;         // at most position by further jump
        for(int i = 0, next; i < n; ++i) {
            if(i > last) {   // he cannot reach "i" by current jumps
                ++ans;       // so he should jump one more time
                last = cur;  // to reach at most position
            }
            cur = max(cur, i + nums[i]); // update at most position by further jump
        }
        return ans;
    }
};