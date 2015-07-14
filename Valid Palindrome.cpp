class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(int i=0; i<s.size(); ++i)
            if( (s[i]>='a'&&s[i]<='z') || (s[i]>='0'&&s[i]<='9') )
                str += s[i];
            else if( (s[i]>='A'&&s[i]<='Z')  )
                str += (s[i]-'A'+'a');
        s = str;
        int len = (int)s.size();
        if(len<=0) return true;
        int l = 0, r = len-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++; r--;
        }
        return true;
    }
};
