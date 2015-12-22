  class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            int res = 0;
            stack<int>index;
        
            height.push_back(0);
            int n = height.size();
            
            int i = 0;
            while(i<n){
                while( !index.empty() && height[index.top()] >= height[i] ){
                    int h = height[index.top()];
                    index.pop();
                    int idx = index.empty()?-1:index.top();
                    res = max(res,(i-idx-1)*h);
                }
                index.push(i++);
            }
            return res;
        }
    };