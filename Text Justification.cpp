class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string>ret;
        int n = (int)words.size();
        if(0==n) return ret;

        int i = 0;
        while(i<n){
            int start = i, end = i;
            string now=words[i++];
            while(i<n && (int)now.size()+(int)words[i].size()+1<=L){
                now = now+" "+words[i];
                i++;
            }
            end = i-1;
            int gaps = end-start;
            int avg = 0, re = 0;
            if(gaps>0){
                avg = ( L-((int)now.size()-gaps) )/gaps;
                re = ( L-((int)now.size()-gaps) )%gaps;
            }
            now = "";
            for(int j=start; j<end; ++j){//without last word
                now+=words[j];
                if(end==n-1) now.append(1,' ');
                else{
                    now.append(avg,' ');
                    if(re){
                        now.append(1,' ');
                        re--;
                    }
                }
            }
            now+=words[end]; //put last word
            if( (int)now.size() < L )
                now.append( L-(int)now.size(), ' ' );
            ret.push_back(now);
        }
        return ret;
    }
};
