class Solution {
public:
    vector<string>ret;
    string dict[10]={" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(int depth,string digits, string s){
        int len = (int)digits.size();
        if(depth>=len){
            if(s.size())
                ret.push_back(s);
            return;
        }
        int x = digits[depth]-'0';
        for(int i=0; i<(int)dict[x].size(); ++i){
            dfs(depth+1,digits,s+dict[x][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        ret.clear();
        dfs(0,digits,"");
        return ret;
    }
};
