/*
stupid problem, push is O(N),other is O(1)
*/

class Stack {
public:
    queue<int>Q;
    // Push element x onto stack.
    void push(int x) {
        Q.push(x);
        for(int i=0; i<(int)Q.size()-1; ++i){
            Q.push( Q.front() );
            Q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        Q.pop();
    }

    // Get the top element.
    int top() {
        return Q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return Q.empty();
    }
};