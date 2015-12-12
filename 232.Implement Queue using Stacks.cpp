/*
O(1) two stack
*/
class Queue {
public:
    // Push element x to the back of queue.
    stack<int>in,out;
    void push(int x) {
        in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!out.empty()) out.pop();
        else{
            while( !in.empty() ) {
                out.push( in.top() );
                in.pop();
            }
            out.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if(!out.empty()) return out.top();
        else{
            while( !in.empty() ) {
                out.push( in.top() );
                in.pop();
            }
            return out.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return in.empty() && out.empty();
    }
};