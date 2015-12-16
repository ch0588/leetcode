/*
Time: O(logN)  Space:O(1)

binary search base below

int hIndex(vector<int>& citations) {
        int res = 0;
        int n = citations.size();
        sort(citations.begin(),citations.end());
        for(int i = 0; i < n; ++i){
            if( citations[i] >= n-i ) return n-i;
        }
        return 0;
    }
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n-1, m, res = 0;
        while(l<=r){
            m = l+(r-l)/2;
            if( citations[m]>=n-m ){
                res = n-m;
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return res;   
    }
};

