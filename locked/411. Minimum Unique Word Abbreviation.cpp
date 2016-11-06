/*
A string such as "word" contains the following abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with the smallest possible length such that it does not conflict with abbreviations of the strings in the dictionary.

Each number or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc" has length = 4.

Note:
In the case of multiple answers as shown in the second example below, you may return any one of them.
Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.
Examples:
"apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")

"apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").
*/

//http://bookshadow.com/weblog/2016/10/02/leetcode-minimum-unique-word-abbreviation/

class Solution {  
public:  
    vector<int>num;
    string minAbbreviation(string target, vector<string>& dictionary) { 
        
        // bool t = checkNumber("5");
        // return "";
        
        int len = target.size();  
        if(len==0) return "";  
        vector<string> dic;  
        num.clear();
        for(string s:dictionary) {  
            if(s.size()==len) {  
                dic.push_back(s);  
                num.push_back(toNumber(target, s));
            }  
        }  
        int len_d=dic.size();  
        if(len_d==0) return to_string(len);  
        string res=target;  
        dfs("",0,target,0,dic,res,len);  
        return res;  
    }  
    bool checkNumber(string w) {
        int number = 0;
        int len = w.length();
        int i = 0;
        while (i < len) {
            if (!isdigit(w[i])) {
                number <<= 1;
                number |= 1;
                i++;
            } else {
                int n = 0;
                while(i < len && isdigit(w[i])) {
                    n = 10 * n + (w[i] - '0');
                    i++;
                }
                number <<= n;
            }
        }
        // cout<<"w:"<<w<<endl;
        for(int i = 0; i < num.size(); ++i) {
            // cout<<"number:"<<number<<"\tnum[i]"<<num[i]<<endl;
            if ((number & num[i]) == number)
                return false;
        }
        return true;
    }
    int toNumber(string target, string word) {
        int res = 0;
        int len = target.length();
        for (int i = 0; i < len; ++i) {
            res <<= 1;
            res += (target[i] == word[i]);
        }
        // cout<<word<<"\t"<<res<<endl;
        return res;
    }
    void dfs(string cur,int cur_len,string& target,int pos,vector<string>&dic,string&res,int& minlen) {  
        if(pos>=(int)target.size()) {  
            if(cur_len<minlen) {  //剪枝  
                // bool f=true;  
                // for(string s:dic) {  
                //     if(validWordAbbreviation(s,cur)) {  
                //         f=false;break;  
                //     }  
                // }  
                // if(f){  
                //     res=cur;  
                //     minlen=cur_len;  
  
                // }  
                if (checkNumber(cur)) {
                    // cout<<"cur\t"<<cur<<endl;
                    res = cur;
                    minlen = cur_len;
                }
            }  
            return;  
        }  
        if(minlen==cur_len) return;   //剪枝  
        if(cur.empty()||!isdigit(cur.back())) {   //  
            for(int i=target.size()-1;i>=pos;i--) {  
                 string add=to_string(i-pos+1);  
                 dfs(cur+add,cur_len+1,target,i+1,dic,res,minlen);  
            }  
        }  
        dfs(cur+target[pos],cur_len+1,target,pos+1,dic,res,minlen);  
    }  
  
    bool validWordAbbreviation(string word, string abbr) {
        int lenw = word.size(), lena = abbr.size();
        int i = 0, j = 0;
        while(i < lenw && j < lena) {
            if(abbr[j] >= 'a' && abbr[j] <= 'z') {
                if(abbr[j] == word[i]) {
                    i++;
                    j++;
                }else {
                    return false;
                }
            }else {
                int now = 0;
                string nn = "";
                while(j < lena && (abbr[j] >= '0' && abbr[j] <= '9')) {
                    nn += abbr[j];
                    now = now * 10 + abbr[j] - '0';
                    j++;
                }
                
                if(now == 0 || nn[0] == '0') return false;
                i += now;
                if(i > lenw) return false;
            }
        }
        if(i < lenw || j < lena) return false;
        return true;
    }
};  

