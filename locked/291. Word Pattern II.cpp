/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.

Show Company Tags
Show Tags
Show Similar Problems

 */
class Solution {
public:
    int lenp,lens;
    bool dfs(string &pattern,string &str,int pp,int ps,unordered_map<char,string>p2s,unordered_map<string,char>s2p){
        if(pp==lenp && ps==lens){
            return true;
        }
        if(pp>=lenp || ps>=lens) return false;
        if(lenp-pp > lens-ps) return false;
        
        char ch = pattern[pp];
        if(p2s.find(ch)!=p2s.end()){
            string s = p2s[ch];
            int len = s.size();
            if(ps+len<=lens && str.substr(ps,len)==s){
                return dfs(pattern,str,pp+1,ps+len,p2s,s2p);
            }
            else{
                return false;
            }
        }
        else{
            string s="";
            for(int i=ps; i<lens; ++i){
                s+=str[i];
                if(s2p.find(s)==s2p.end()){
                    p2s[ch] = s;
                    s2p[s] = ch;
                    if( dfs(pattern,str,pp+1,i+1,p2s,s2p) ) return true;
                    p2s.erase(ch);
                    s2p.erase(s);
                }
            }
            return false;
        }
    }
    bool wordPatternMatch(string pattern, string str) {
        lenp = pattern.size();
        lens = str.size();
        if(lenp==0 && lens==0) return true;
        if(lenp==0 || lens==0) return false;
        unordered_map<char,string>p2s;
        unordered_map<string,char>s2p;
        return dfs(pattern,str,0,0,p2s,s2p);
    }
};