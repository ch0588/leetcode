// Time Complexity: O(n)
// Space Complexity: O(n)

/*
 首先统计每个单词最后出现的位置。
 维护堆栈，大体上当栈顶元素大于当前元素就将栈顶元素出栈，只有一种情况不出栈，就是后面再也没有栈顶元素所代表的字母了。
 入栈前要判重。
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last_pos[26] = {0};
        bool visited[26] = {0};
        
        for (int i = 0; i < s.size(); ++i) last_pos[s[i] - 'a'] = i;
        stack<char> ret;
        while (!ret.empty()) ret.pop();
        
        for (int i = 0; i < s.size(); ++i) {
            if (visited[s[i] - 'a']) continue;
            while (!ret.empty() && last_pos[ret.top() - 'a'] >= i &&
                   ret.top() > s[i]) {
                visited[ret.top() - 'a'] = false;
                ret.pop();
            }
            visited[s[i] - 'a'] = true;
            ret.push(s[i]);
        }
        string ans = "";
        while (!ret.empty()) {
            ans += ret.top();
            ret.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};