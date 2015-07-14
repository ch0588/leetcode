class Solution {
    int fac(int n){
        if(n<=1) return 1;
        return fac(n-1)*n;
    }
public:
    string getPermutation(int n, int k){
        k--;
        vector<int>a(n);
        for(int i=0; i<n; ++i){
            a[i] = k / fac(n-1-i);
            k = k % fac(n-1-i);
        }
        vector<bool>H(n);
        for(int i=0; i<n; ++i) H[i] = false;
        string s = "";
        for(int i=0; i<n; ++i){
            int cnt = 0;
            for(int j=0; j<n; ++j){
                if(!H[j]){
                    cnt++;
                }
                if(cnt>a[i]){
                    H[j] = true;
                    s+=(j+1+'0');
                    break;
                }
            }
        }
        return s;
    }
};
