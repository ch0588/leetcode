class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = (int)strs.size();
        if(n==0) return "";
        int len = strs[0].size();
        for(int i=0; i<n; ++i)
            len = min(len,(int)strs[i].size());

        string s = "";
        for(int i=0; i<len; ++i){
            bool flag = false;
            for(int j=1; j<n; ++j)
                if(strs[0][i]!=strs[j][i]){
                    flag = true;
                    break;
                }
            if(flag) break;
            else s+=strs[0][i];
        }
        return s;
    }
};
