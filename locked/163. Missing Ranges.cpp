Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

class Solution {
    string rangeToString(int l,int r){
        if(l==r) return to_string(l);
        return to_string(l)+"->"+to_string(r);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string>res;
        if(lower>upper) return res;

        int cur = lower-1;
        int n = nums.size();
        for(int i=0; i<n; ++i){
            if(nums[i]>cur+1)
                res.push_back( rangeToString(cur+1,nums[i]-1) );
            cur = nums[i];
        }
        if(cur<upper) res.push_back( rangeToString(cur+1,upper) );
        return res;
    }
};