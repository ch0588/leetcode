class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int>res;
        int lenS = S.size(), lenL = L.size();
        if (lenL == 0) return res;
        
        unordered_map<string,int>dict;
        for (int i = 0; i < lenL; ++i) {
            dict[L[i]] = dict[L[i]] + 1;
        }
        
        int len = L[0].size();
        for (int i = 0; i <= lenS - lenL * len; ++i) {
            unordered_map<string,int>H;
            int j = i;
            bool flag = true;
            for (int k = 0; k < lenL; ++k) {
                string s = S.substr(j, len);
                if (dict.find(s) == dict.end()){
                    flag= false;
                    break;
                }
                if ( H.find(s) == H.end() ) H[s] = 1;
                else H[s] = H[s] + 1;

                if (H[s] > dict[s]) {
                    flag = false;
                    break;
                }
                j += len;
            }
            if(flag) res.push_back(i);
        }
        return res;
    }
};
