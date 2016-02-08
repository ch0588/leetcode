class Solution {
public:
    bool isValid(string s) {
        stack<char>S;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                S.push(s[i]);
            }
            else{
                if(S.empty()) return false;
                char ch = S.top();
                if( (s[i]==')'&&ch=='(') || (s[i]=='}'&&ch=='{') || (s[i]==']'&&ch=='[') )
                    S.pop();
                else
                    return false;
            }
        }
        if(S.empty()) return true;
        else return false;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
        bool isValid(string s) {
            const string left = "([{";
            const string right = ")]}";
            stack<char> stack;
            for(auto c : s) {
                if(left.find(c) != string::npos) {
                    stack.push(c);
                }
                else if (right.find(c) != string::npos){
                    if(!stack.empty() && stack.top() == left[right.find(c)]) {
                        stack.pop();
                    }
                    else
                        return false;
                }
            }

            return stack.empty();
        }
};