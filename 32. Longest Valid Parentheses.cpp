// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
    
        stack<int> st;
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                if(st.empty()) {
                    last = i;
                } else {
                    st.pop();
                    if(st.empty())
                        res = max(res, i - last); //full match
                    else
                        res = max(res, i - st.top()); //find the matched left
                }
            }
        }
        return res;
    }
};

