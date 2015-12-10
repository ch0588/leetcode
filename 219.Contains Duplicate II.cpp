/*
O(N)*hash，类似滑动窗口
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_multimap<int, bool> hash;
        for(int i=0; i<nums.size(); ++i){
            if(i>k) hash.erase(nums[i-k-1]);
            if(hash.find(nums[i]) != hash.end())
                return true;
            hash.insert(make_pair(nums[i], true));
        }
        return false;
    }
};