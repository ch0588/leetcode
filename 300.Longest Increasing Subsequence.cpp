/*
nlogn
refer to https://leetcode.com/discuss/67533/c-typical-dp-2-solution-and-nlogn-solution-from-geekforgeek
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        for( auto item:nums ){
            auto it = lower_bound(res.begin(),res.end(),item);
            if(it==res.end()) res.push_back(item);
            else *it = item;
        }
        return res.size();
    }
};