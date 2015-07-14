class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int ret = 0,diff = INT_MAX;
        for(int i=0; i<(int)num.size()-2; ++i){
            int t = target - num[i];
            int l=i+1,r = (int)num.size()-1;
            while(l<r){
                if( abs(target-(num[i]+num[l]+num[r]))<diff ){
                    diff=abs(target-(num[i]+num[l]+num[r]));
                    ret = num[i]+num[l]+num[r];
                }
                if( num[l]+num[r] < t )
                    l++;
                else
                    r--;
            }
        }
        return ret;
    }
};
