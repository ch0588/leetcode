#include<stdio.h>
#include<string>
#include<string.h>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

int longestValidParentheses(string s) {
    int n = (int)s.size();
    int ans = 0;

    stack<int>st;
    while(!st.empty()) st.pop();
    int last = -1;
    for(int i=0; i<n; ++i) {
        if(s[i]=='(') {
            st.push(i);
        } else {
            if(st.empty()) {
                last = i;
            } else {
                st.pop();
                if(st.empty())
                    ans = max(ans,i-last); //full match
                else
                    ans = max(ans,i-st.top()); //find the matched left
            }
        }
    }
    return ans;
}

char in[1000010];
int main() {
    freopen("in.cpp","r",stdin);
    while(~scanf("%s",in)) {
        printf("%d\n",longestValidParentheses(string(in)));
    }
    return 0;
}
