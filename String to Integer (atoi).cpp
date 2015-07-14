class Solution {
public:
    int atoi(const char *str) {
        int len = (int)strlen(str);
        if(len<1) return 0;

        string s="";
        int i=0;
        while(str[i]==' ' && i<len) i++;
        for( ;i<len; ++i)
            if( (str[i]>='0'&&str[i]<='9') || str[i]=='-' || str[i]=='+' )
                s+=str[i];
            else break;

        len = (int)s.size();

        i=0;
        long long sign = 1;
        while( (s[i]=='+'||s[i]=='-') && i<len){
            if(s[i]=='-') sign *= -1;
            i++;
        }
        if(i>1) return 0;
        long long ans = 0;
        while(i<len){
            ans = 10*ans + s[i]-'0';
            i++;
            if(ans*sign>INT_MAX) return INT_MAX;
            if(ans*sign<INT_MIN) return INT_MIN;
        }
        return ans*sign;
    }
};
