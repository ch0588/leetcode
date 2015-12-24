class NumArray {
public:
    typedef long long ll;
    ll *sum;
    NumArray(vector<int> &nums) {
        int n = nums.size();
        if(n==0) return;
        
        sum = new ll[n];
        sum[0] = (ll)nums[0];
        for(int i=1; i<n; ++i)
            sum[i] = sum[i-1] + (ll)nums[i];
    }

    int sumRange(int i, int j) {
        if(i==0) return (int)sum[j];
        return (int)(sum[j]-sum[i-1]);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);