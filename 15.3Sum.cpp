/*
sort后，枚举第一个数，后两个数two pointer。时间复杂度O(N^2),注意判重
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> >ret;
        ret.clear();
        sort(num.begin(), num.end());
        int n = num.size();
        for(int i=0; i<n; ++i){
            if (i > 0 && num[i] == num[i-1]) continue; //第一个数不能重复
            int l = i+1, r = n-1;
            int target = -1*num[i];
            int prel = num[i]-1; //第二个数判重
            while(l<r){
                if(num[l]+num[r]==target){
                    if(num[l]!=prel){ //对于同一个i，第二个数不能重复
                    vector<int>t;
                        prel = num[l];
                        ret.push_back({num[i],num[l],num[r]});
                    }
                    l++; r--;
                }
                else if(num[l]+num[r]<target) l++;
                else r--;
            }
        }
        return ret;
    }
};
