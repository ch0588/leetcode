class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=n-1;
        for(int i=0; i<n; ++i){
            while(nums[i]==2 && i<r)     //two while order can't change
                swap(nums[i],nums[r--]);
            while(nums[i]==0 && i>l) 
                swap(nums[i],nums[l++]);
        }
    }
};