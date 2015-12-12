class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int remain = 0;
        int n = (int)nums.size();
        for(int i=0; i<n; ++i)
            remain ^= (nums[i]);
        
        int lastOne = remain&(-remain); //low bit
        
        int a=0,b=0;
        for(int i=0; i<n; ++i){
            if(nums[i]&lastOne)
                a^=nums[i];
            else
                b^=nums[i];
        }
        vector<int>res;
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};