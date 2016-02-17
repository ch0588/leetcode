class MedianFinder {
public:
    //always maintain min_heap top >= max_heap top
    std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
    std::priority_queue<int> max_heap;
    int cnt=0;
    // Adds a number into the data structure.
    MedianFinder(){
        while(!min_heap.empty()) min_heap.pop();
        while(!max_heap.empty()) max_heap.pop();
        cnt = 0;
    }
    void addNum(int num) {
        if(min_heap.empty() && max_heap.empty()){
            min_heap.push(num);
            return;
        }
        if(max_heap.empty()){
            if(num > min_heap.top()){
                max_heap.push( min_heap.top() );
                min_heap.pop();
                min_heap.push(num);
            }
            else{
                max_heap.push( num );
            }
            return;
        }
        
        if(num >= min_heap.top() )
            min_heap.push(num);
        else
            max_heap.push(num);
        
        while( abs( min_heap.size()-max_heap.size() ) > 1 ){
            if( min_heap.size() > max_heap.size() ){
                max_heap.push( min_heap.top() );
                min_heap.pop();
            }
            else{
                min_heap.push( max_heap.top() );
                max_heap.pop();
            }
        }
        if(cnt++<5)
            printf("num=%d min=%d max=%d\n",num,min_heap.size(),max_heap.size());
    }
    
    // Returns the median of current data stream
    double findMedian() {
        int n = min_heap.size() + max_heap.size();
        if(n<=0) return 0.0;
        if(n==1) return (double)min_heap.top();
        if(n&1){
            if(min_heap.size() > max_heap.size()) return (double)min_heap.top();
            else return (double)max_heap.top();
        }
        else{
            return ((double)min_heap.top()+(double)max_heap.top())/2.0;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

// Time Complexity: O(logn) per option
// Space Complexity: O(n)

/*
 min_heap.size() always >= max_heap.size()
 */
class MedianFinder {
public:
    //always maintain min_heap top >= max_heap top
    std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
    std::priority_queue<int> max_heap;
    // Adds a number into the data structure.
    MedianFinder(){
        while(!min_heap.empty()) min_heap.pop();
        while(!max_heap.empty()) max_heap.pop();
    }
    void addNum(int num) {
        min_heap.push(num);
        max_heap.push(min_heap.top());
        min_heap.pop();
        if (min_heap.size() < max_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {
        return min_heap.size() > max_heap.size()
        ? min_heap.top()
        : (min_heap.top() + max_heap.top()) / 2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();


