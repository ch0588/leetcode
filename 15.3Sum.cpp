/*
sort��ö�ٵ�һ��������������two pointer��ʱ�临�Ӷ�O(N^2),ע������
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> >ret;
        ret.clear();
        sort(num.begin(), num.end());
        int n = num.size();
        for(int i=0; i<n; ++i){
            if (i > 0 && num[i] == num[i-1]) continue; //��һ���������ظ�
            int l = i+1, r = n-1;
            int target = -1*num[i];
            int prel = num[i]-1; //�ڶ���������
            while(l<r){
                if(num[l]+num[r]==target){
                    if(num[l]!=prel){ //����ͬһ��i���ڶ����������ظ�
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
