class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)nums.size();
        int ret = 0, cnt = 0;
        for(int i=0; i<n; ++i){
            if(cnt==0){
                ret = nums[i];
                cnt = 1;
            }
            else{
                if(ret==nums[i])
                    cnt++;
                else
                    cnt--;
            }
        }
        return ret;
    }
};