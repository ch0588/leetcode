// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
public:
    int lower(vector<int>& A, int target) {
        int l = 0, r = (int)A.size() - 1, m, res = -1;
        while (l <= r) {
            m = (l + r) / 2;
            if (A[m] >= target) { 
                if (A[m] == target) res = m;
                r = m - 1;
            } else{
                l = m + 1;
            }
        }
        return res;
    }
    int upper(vector<int>& A, int target) {
        int l = 0, r = (int)A.size() - 1, m, res = -1;
        while (l <= r) {
            m = (l + r) / 2;
            if (A[m] <= target) { 
                if (A[m] == target) res = m;
                l = m + 1;
            } else{
                r = m - 1;
            }
            cout<<m<<" "<<res<<endl;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower(nums, target);
        int r = upper(nums, target);
        vector<int> res{l, r};
        return res;
    }
};


// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        if (begin <= end) 
            return {begin, end};

        return {-1, -1};
    }
};