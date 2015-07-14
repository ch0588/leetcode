/*
http://blog.csdn.net/perfumekristy/article/details/8713083
组合数防止溢出
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ret;
        for(int i=0; i<=rowIndex; ++i){
            long long sum = 1;
            for(int j=1;j<=i; j++) {
                sum=sum*(rowIndex-i+j)/j;
            }
            ret.push_back( (int)sum );
        }
        return ret;
    }
};
