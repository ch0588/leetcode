class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> >ret;
        if(numRows<=0) return ret;
        vector<int>now;
        now.push_back(1);
        ret.push_back(now);
        if(numRows==1) return ret;

        for(int i=1; i<numRows; ++i){
            now.clear();
            now.push_back(1);
            for(int j=1; j<ret[i-1].size(); ++j)
                now.push_back(ret[i-1][j-1]+ret[i-1][j]);
            now.push_back(1);
            ret.push_back(now);
        }
        return ret;
    }
};
