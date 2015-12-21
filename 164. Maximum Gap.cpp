/*
关键是理解max gap的下限是 max(1,(maxV-minV)/(n-1))，因此组内肯定不会产生max gap
之后分组，size = max(1,(maxV-minV)/(n-1))， num = (maxV-minV)/block_size + 1;
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        
        int maxV = INT_MIN,minV = INT_MAX;
        for(auto x:nums){
            maxV = max(maxV,x);
            minV = min(minV,x);
        }
        
        int block_size = max(1,(maxV-minV)/(n-1));
        int block_num = (maxV-minV)/block_size + 1;
        if(block_num<=1) return maxV-minV;
        
        vector<int>block_max(block_num,INT_MIN);
        vector<int>block_min(block_num,INT_MAX);
        
        for(auto x:nums){
            int id = (x-minV)/block_size;
            block_max[id] = max(x,block_max[id]);
            block_min[id] = min(x,block_min[id]);
        }
        
        int res = 0;
        int last = minV;
        for(int i=0; i<block_num; ++i){
            if(block_min[i]==INT_MAX && block_max[i]==INT_MIN) continue;
            res = max(res,block_min[i]-last);
            last = block_max[i];
        }
        
        return res;
    }
};