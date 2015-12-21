class NumArray {
public:
    vector<int>C;
    int n;
    int lowbit(int x){
        return x&(-x);
    }
    NumArray(vector<int> &nums) {
        n = nums.size();
        C.reserve(n+1);
        for(int i=0; i<=n; ++i) C[i] = 0;
        
        for(int i=0; i<n; ++i)
            update(i,nums[i]);
    }

    void update(int i, int val) {
        val -= sumRange(i,i);
        i++;
        while(i<=n){
            C[i] += val;
            i+=lowbit(i);
        }
    }

    int preSum(int i){
        if(i<0) return 0;
        i++;
        int sum = 0;
        while(i>0){
            sum += C[i];
            i-=lowbit(i);
        }
        return sum;    
    }
    int sumRange(int i, int j) {
        return preSum(j)-preSum(i-1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);