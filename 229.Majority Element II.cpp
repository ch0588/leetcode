class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt[2]={0}, ret[2];
    
        for(int i=0; i<n; ++i){
            if(cnt[0]==0 || nums[i]==ret[0]){
                cnt[0]++; ret[0] = nums[i];
            }
            else if(cnt[1]==0 || nums[i]==ret[1]){
                cnt[1]++; ret[1] = nums[i];
            }
            else{
                cnt[0]--; cnt[1]--;
            }
        }
        
        cnt[0] = cnt[1] = 0;
        for(int i=0 ;i<n; ++i){
            if(nums[i]==ret[0]) cnt[0]++;
            else if(nums[i]==ret[1]) cnt[1]++; //must else!!! [-1,1,1,1,2,1] or will get double 1
        }
        vector<int>ans;
        if(cnt[0]>n/3) ans.push_back(ret[0]);
        if(cnt[1]>n/3) ans.push_back(ret[1]);
        return ans;
    }
};