/*
"hello world!" -> "world! hello"
*/
class Solution {
    bool isSym(char c){
        if(c=='?'||c=='.'||c==','||c=='!') return true;
        false;
    }
    void dealSym(string &s){
        int pos=0;
        string t="";
        while(pos<s.size() && isSym(s[pos])) pos++;
        t = s.substr(pos,(int)s.size()-pos) + s.substr(0,pos);
        s = t;
    }
public:
    void reverseWords(string &s) {
        reverse(s.begin(),s.end());
        vector<string>str;

        int i = 0;
        while(i<(int)s.size()){
            while(s[i]==' ' && i<(int)s.size()) i++;
            if(i>=(int)s.size()) break;
            string t = "";
            while(s[i]!=' '&&i<(int)s.size()){
                t+=s[i];
                i++;
            }
            reverse(t.begin(),t.end());
            dealSym(t);
            str.push_back(t);
        }
        if((int)str.size()==0) s="";
        else{
            s=str[0];
            for(int i=1; i<str.size(); ++i)
                s = s+" "+str[i];
        }
    }
};

