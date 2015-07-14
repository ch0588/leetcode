class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int>ret;
        if(L.size()==0) return ret;
        map<string,int>dict;
        for(int i=0; i<L.size(); ++i) {
            if ( dict.find(L[i])==dict.end() ) dict[L[i]] = 1;
            else dict[L[i]] = dict[L[i]] + 1;
        }
        //printf("OK %d\n",S.size()-L.size()*L[0].size());
        for(int i=0; i<=(int)S.size()-(int)L.size()*(int)L[0].size(); ++i){
            map<string,int>H;
            int j = i;
            bool flag = true;
            for(int k=0; k<L.size(); ++k){
                string s = S.substr(j,L[0].size());
                if(dict.find(s)==dict.end()){
                    flag= false;
                    break;
                }
                if ( H.find(s) == H.end() ) H[s] = 1;
                else H[s] = H[s] + 1;

                if(H[s]>dict[s]){
                    flag = false;
                    break;
                }
                j+=L[0].size();
            }
            if(flag) ret.push_back(i);
        }
        return ret;
    }
};
