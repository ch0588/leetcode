class MinStack {
    stack<int>S,M;
public:
    void push(int x) {
        S.push(x);
        if(M.empty() || M.top()>=x) M.push(x);
    }

    void pop() {
        if(S.top()==M.top()) M.pop();
        S.pop();
    }

    int top() {
        return S.top();
    }

    int getMin() {
        return M.top();
    }
};
