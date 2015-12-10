class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        
        int i=0, j=1;
        bool first = true;
        int ret = 0;
        while( j<(int)nums.size() ){
            while( j<(int)nums.size() && nums[i]==nums[j] ){
                if(first){
                    nums[++i] = nums[j];
                }
                first = false;
                j++;
            }
            first = true;
            if(j<(int)nums.size())
                nums[++i] = nums[j++];
        }
        return i+1;
    }
};