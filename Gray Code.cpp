/*
0
1

0 00
1 01
1 11
0 10

00 000
01 001
11 011
10 010
10 110
11 111
01 101
00 100
*/
class Solution {
public:
    int str2int(string s){
        int ans = 0;
        for(int i=0; i<s.size(); ++i){
            ans = 2*ans + s[i]-'0';
        }
        return ans;
    }
    vector<int> grayCode(int n) {
        vector<int>ans;
        if(n<0)
            return ans;
        if(n==0){
            ans.push_back(0);
            return ans;
        }
        vector<string>gray;
        gray.push_back("0");
        gray.push_back("1");
        for(int i=2; i<=n; ++i){
            for(int j=(int)gray.size()-1; j>=0; --j) //reverse copy
                gray.push_back(gray[j]);

            int n = (int)gray.size();
            for(int i=0; i<n/2; ++i) //add prefix 0
                gray[i] = "0" + gray[i];
            for(int i=n/2; i<n; ++i) //add prefix 1
                gray[i] = "1" + gray[i];
        }
        for(int i=0; i<gray.size(); ++i)
            ans.push_back( str2int(gray[i]) ); //string to int
        return ans;
    }
};
