//https://leetcode.com/discuss/58186/elegant-c-solution-o-n-space-time-with-detailed-explanation
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>res;
        res.push_back(1);
        int i,j,k;
        i = j = k = 0;
        for(int _=1; _<n; ++_){
            res.push_back( min( min( res[i]*2,res[j]*3),res[k]*5 ) );
            if(res.back() == res[i]*2) i++;
            if(res.back() == res[j]*3) j++;
            if(res.back() == res[k]*5) k++;
        }
        return res.back();
    }
};