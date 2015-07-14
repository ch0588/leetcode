class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int n = (int)S.size();
        int sumStates = 1<<n;
        sort(S.begin(),S.end());
        vector<vector<int> >ret;
        for(int i=0; i<sumStates; ++i){
            vector<int>temp;
            for(int j=0; j<n; ++j)
                if( (i>>j)&1 )
                    temp.push_back(S[j]);
            ret.push_back(temp);
        }
        return ret;
    }
};
