// Time Complexity: O(3^n)
// Space Complexity: O(n)

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        dfs(0, digits, "");
        return res;
    }
private:
    vector<string> res;
    string dict[10]={" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void dfs(int depth, string digits, string s){
        int len = digits.size();
        if (depth >= len) {
            if( s.size() )
                res.push_back(s);
            return;
        }
        int x = digits[depth] - '0';
        for (int i = 0; i < dict[x].size(); ++i) {
            dfs(depth + 1, digits, s + dict[x][i]);
        }
    }

};
