#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iostream>
#include<string>
using namespace std;
    void update(string &s,int pos, int val){
        int r = val;
        //cout<<s<<"\t"<<pos<<"\t"<<val<<endl;
        while(r>0){
            //cout<<"r="<<r<<endl;
            if(pos>=(int)s.size()) s+="0";
            r += (s[pos]-'0');
            s[pos] = r%10 + '0';
            r = (r - r%10)/10;
            pos++;
        }
    }
    string multiply(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int l1 = (int)num1.size();
        int l2 = (int)num2.size();
        string ret = "";
        for(int i=0; i<=l1+l2; ++i) ret+="0";

        for(int i=0; i<l1; ++i)
            for(int j=0; j<l2; ++j){
                //printf("%d %d\n",i,j);
                update(ret,i+j,(num1[i]-'0')*(num2[j]-'0'));
            }
        string ans = "";
        int i = (int)ret.size()-1;
        while(ret[i]=='0') i--;
        for(int j=i; j>=0; --j) ans+=ret[j];
        if((int)ans.size()==0) ans = "0";
        return ans;
    }
int main() {
    //freopen("1.out","w",stdout);
    //    ["","","","","","","","",""]
    cout<<multiply("1234","9");
    return 0;
}

