class Solution {
public:
    typedef long long ll;
    vector<int> productExceptSelf(vector<int>& nums) {
        ll mul = 1LL,num0 = 0;
        int n = nums.size();
        vector<int>res(n);
        for(auto x:nums){
            if(x==0) num0++;
            else mul *=x;
        }
        for(int i=0; i<n; ++i){
            if(num0>1 || (num0==1&&nums[i]!=0) ) res[i] = 0;
            else if(nums[i]==0) res[i] = mul;
            else res[i] = mul/nums[i];
        }
        return res;
    }
};