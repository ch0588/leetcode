/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int _size) {
        size = _size;
        sum = 0;
        Q.clear();
    }
    
    double next(int val) {
        if ((int)Q.size() < size) {
            Q.push_back(val);
            sum += val;
        } else {
            if (!Q.empty()) {
                sum -= Q.front();
                Q.pop_front();
            }
            Q.push_back(val);
            sum += val;
        }
        
        int n = (int)Q.size();
        return n == 0 ? 0 : (double)sum / n;
    }
private:
    int size, sum;
    deque<int>Q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */