class Solution {
public:
    typedef long long ll;
    string fractionToDecimal(ll numerator, ll denominator) {
        if(denominator==0LL || numerator==0LL) return "0";
        
        unordered_map<ll,ll>hash;
        string res;
        if(numerator<0 ^ denominator<0){
            res = "-";
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        ll n = numerator / denominator;
        res += to_string(n);
        numerator -= denominator*n;
        
        if(numerator!=0)
            res+=".";
        
        vector<ll>remain;
        while(numerator!=0){
            ll r = numerator*10/denominator;
            //printf("n=%lld\n",numerator);
            
            if(hash.find(numerator)!=hash.end()){
                int start = hash[numerator];
                for(int i=0; i<start; ++i)
                    res+=to_string(remain[i]);
                res+="(";
                int len = remain.size();
                for(int i=start; i<len; ++i)
                    res += to_string(remain[i]);
                res+=")";
                return res;
            }
            
            hash[numerator] = remain.size();
            remain.push_back(r);
            numerator = numerator*10L - denominator*r;
        }
        
        for(auto x:remain)
            res += to_string(x);
        return res;
    }
};