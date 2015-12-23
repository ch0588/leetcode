class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        int n = s.size();
        if(n<10) return res;
        
        unordered_map<string,int>hash;
        for(int i=0; i<=n-10; ++i){
            string t = s.substr(i,10);
            hash[t]++;
            if(hash[t]==2) res.push_back(t);
        }
        return res;
    }
};