class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        vector<int>res;
        res.push_back(1);
        vector<int>index;
        for(int i=0; i<primes.size(); ++i) index.push_back(0);
        
        for(int _=1; _<n; ++_){
            int t = INT_MAX;
            for(int i=0; i<primes.size(); ++i)
                t = min(t,primes[i]*res[index[i]]);
            res.push_back(t);
            for(int i=0; i<primes.size(); ++i)
            if( t == primes[i]*res[index[i]] ) index[i]++;
        }
        return res.back();
    }
};