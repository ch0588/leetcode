class Solution {
public:
    typedef long long ll;
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        ll left[n][2],right[n][2]; 
        left[0][0] = left[0][1] = 1; //0 is pos,1 neg
        for(int i=1; i<n; ++i){
            if(nums[i-1]<0){
                left[i][0] = max(1LL,left[i-1][1]*nums[i-1]);
                left[i][1] = min(1LL,left[i-1][0]*nums[i-1]);
            }
            else if(nums[i-1]>0){
                left[i][0] = max(1LL,left[i-1][0]*nums[i-1]);
                left[i][1] = min(1LL,left[i-1][1]*nums[i-1]);
            }
            else
                left[i][0] = left[i][1] = 1;
        }
        right[n-1][0] = right[n-1][1] = 1;
        for(int i=n-2; i>=0; --i){
            if(nums[i+1]<0){
                right[i][0] = max(1LL,right[i+1][1]*nums[i+1]);
                right[i][1] = min(1LL,right[i+1][0]*nums[i+1]);
            }
            else if(nums[i+1]>0){
                right[i][0] = max(1LL,right[i+1][0]*nums[i+1]);
                right[i][1] = min(1LL,right[i+1][1]*nums[i+1]);
            }
            else
                right[i][0] = right[i][1] = 1;
        }
        /*
        for(int i=0; i<n; ++i){
            printf("left i=%d %d %d\n",i,left[i][0],left[i][1]);
            printf("right i=%d %d %d\n",i,right[i][0],right[i][1]);
        }
        */
        ll res = (ll)nums[0];
        for(int i=0; i<n; ++i){
            if(nums[i]==0){
                res = max(res,0LL);
            }
            else if(nums[i]>0){
                res = max(res,nums[i]*left[i][0]*right[i][0]);
                res = max(res,nums[i]*left[i][1]*right[i][1]);
            }
            else{
                res = max(res,nums[i]*left[i][0]*right[i][1]);
                res = max(res,nums[i]*left[i][1]*right[i][0]);
            }
        }
        
        return (int)res;
    }
};

//dp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int nmax[n],nmin[n],res;
        res = nmax[0] = nmin[0] = nums[0];
        for(int i=1; i<n; ++i){
            nmax[i] = nmin[i] = nums[i];
            if(nums[i]>0){
                nmax[i] = max(nmax[i],nmax[i-1]*nums[i]);
                nmin[i] = min(nmin[i],nmin[i-1]*nums[i]); 
            }
            else{
                nmax[i] = max(nmax[i],nmin[i-1]*nums[i]);
                nmin[i] = min(nmin[i],nmax[i-1]*nums[i]); 
            }
            //printf("i=%d res=%d %d %d\n",i,res,nmax[i],nmin[i]);
            res = max(res,nmax[i]);
        }
        return res;
    }
};