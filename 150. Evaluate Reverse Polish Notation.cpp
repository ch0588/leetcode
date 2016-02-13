// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> op;
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        op.clear();
        for (int i = 0; i < len; ++i) {
            string s = tokens[i];
            if ((s[0] >= '0' && s[0] <= '9') || (int)s.size() > 1) {
                op.push_back(stoi(s));
            } else {
                int a = op.back();
                op.pop_back();
                int b = op.back();
                op.pop_back();
                if (s == "+")
                    op.push_back(a + b);
                else if (s == "-")
                    op.push_back(b - a);
                else if (s == "*")
                    op.push_back(a * b);
                else
                    op.push_back(b / a);
            }
        }
        return op.back();
    }
};