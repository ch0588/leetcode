class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==0) return "";
        if(nRows==1) return s;

        vector<string>ret(nRows);
        int dir = 1, r = 0;
        for(int i=0; i<s.size(); ++i) {
            //printf("r=%d\n",r);
            ret[r] += s[i];
            r+=dir;
            if(r>=nRows) {
                dir = -1;
                r = nRows-2;
            }
            if(r<0) {
                dir = 1;
                r = 1;
            }
        }
        string ans="";
        for(int i=0; i<nRows; ++i) {
            //cout<<ret[i]<<endl;
            ans+=ret[i];
        }
        return ans;
    }
};
