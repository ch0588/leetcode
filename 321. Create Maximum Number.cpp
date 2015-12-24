//http://algobox.org/2015/12/24/create-maximum-number/ worst time O( (n+m)^3 )
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>res;
        for(int i=max(0,k-m); i<=k && i<=n; ++i){
            vector<int>candidate = merge(maxArray(nums1,i),maxArray(nums2,k-i),k);
            if(compare(candidate,0,res,0)) res = candidate;
        }
        return res;
    }
    
    vector<int> merge(vector<int>nums1,vector<int>nums2,int k){
        vector<int>res(k);
        for(int i=0,j=0,r=0;r<k;++r)
            res[r] = compare(nums1,i,nums2,j)?nums1[i++]:nums2[j++];
        return res;
    }
    bool compare(vector<int>nums1,int i,vector<int>nums2,int j){
        int n = nums1.size();
        int m = nums2.size();
        while(i<n && j<m && nums1[i]==nums2[j]){
            i++; j++;
        }
        return j==m || (i<n&&nums1[i]>nums2[j]);
    }
    vector<int> maxArray(vector<int>nums,int k){
        int n = nums.size();
        vector<int>res(k);
        for(int i=0,j=0; i<n; ++i){
            while(n-i+j>k&&j>0&&res[j-1]<nums[i]) j--;
            if(j<k) res[j++] = nums[i];
        }
        return res;
    }
};