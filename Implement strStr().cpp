class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int lenh = (int)strlen(haystack);
        int lenn = (int)strlen(needle);

        for(int i=0; i<=lenh-lenn; ++i){
            bool flag = true;
            for(int j=0; j<lenn; ++j)
                if(needle[j]!=haystack[i+j]){
                    flag = false;
                    break;
                }
            if(flag) return i;
        }

        return -1;

    }
};
