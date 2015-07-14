/*
Anagrams:只考虑组合，不考虑排列
将string字典序sort，然后map
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string,vector<string>>H;
        for(int i=0; i<strs.size(); ++i){
            string s = strs[i];
            sort(s.begin(),s.end());
            H[s].push_back(strs[i]);
        }
        vector<string>ret;
        for(map<string,vector<string>>::iterator it=H.begin(); it!=H.end(); it++){
            if(it->second.size()>1){
                ret.insert(ret.end(),it->second.begin(),it->second.end());
            }
        }
        return ret;
    }
};
