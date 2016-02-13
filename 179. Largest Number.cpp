/*
贪心 sort
考虑两两之间的大小关系，无非ab或ba两种形式
特殊考虑"00"

121 12
128 12
*/
class Solution {
public:
    static bool cmp(string a,string b){
        string c = a+b;
        string d = b+a;
        return c<d;
    }
    string i2s(int x){
        if(x==0) return "0";
        string ans = "";
        while(x){
            ans += (x%10+'0');
            x/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string largestNumber(vector<int> &num) {
        vector<string>str;
        for(int i=0; i<num.size(); ++i){
            str.push_back( i2s(num[i]) );
        }
        sort(str.begin(), str.end(), cmp);
        string ans = "";
        for(int i=(int)str.size()-1; i>=0; --i)
            ans+=str[i];

        bool not0 = false;
        for(int i=0; i<ans.size(); ++i)
            if(ans[i]!='0') not0 = true;
        if(not0==false) return "0";
        else return ans;
    }
};
