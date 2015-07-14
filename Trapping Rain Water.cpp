/*
A[]0,1,0,2,1,0,1,3,2,1,2,1
L[]0 1 1 2 2 2 2 3 3 3 3 3
R[]3 3 3 3 3 3 3 3 2 2 2 1
min0 1 1 2 2 2 2 3 2 2 2 1
ans0 0 1 0 1 2 1 0 0 1 0 0
*/
class Solution {
public:
    int trap(int A[], int n) {

        vector<int>L(n+1);
        int high = 0;
        for(int i=0; i<n; ++i){
            high = max(high,A[i]);
            L[i] = high;
        }
        high = 0;
        int ans = 0;
        for(int i=n-1; i>=0; --i){
            high = max(high,A[i]);
            ans += (min(high,L[i])-A[i]);
        }
        return ans;
    }
};
