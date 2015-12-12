class Solution {
public:
    string minWindow(string s, string t) {
        int inT[128] = {0};
        for(int i=0; i<t.size(); ++i) inT[ t[i] ]++;
        int count = 0;
        count = (int)t.size();
        
        int num[128]={0};
        pair<int,int>pos;
        int minLen = (int)s.size() + 1;
        int start = 0;
        for(int i=0; i<(int)s.size(); ++i){
            if( !inT[ s[i] ] ) continue; //ignore char not in T
            
            if(num[ s[i] ] < inT[ s[i] ])
                count--;
            num[ s[i] ]++;
            while(count==0){
                //printf("i=%d a=%d b=%d c=%d %d\n",i,num['A'],num['B'],num['C'],start);
                if( minLen > i-start+1 ){
                    minLen = i-start+1;
                    pos = make_pair(start,i);
                }
                if( inT[ s[start] ] ){  //ignore char not in T
                    num[ s[start] ]--;
                    if( num[ s[start] ] < inT[ s[start] ] ) count++;
                }
                start++;
            }
        }
        //printf("%d\n",minLen);
        if(minLen == (int)s.size() + 1) return "";
        string res =  s.substr(pos.first,minLen);
        return res;
    }
};