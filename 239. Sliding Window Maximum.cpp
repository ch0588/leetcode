/*
 similar to Min Stack
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        if (n == 0) return res;
        deque<int> maxQ;
        queue<int> window;
        for (int i = 0; i < n; ++i) {
            window.push(nums[i]);
            while (!maxQ.empty() && nums[i] > maxQ.back()) maxQ.pop_back();
            maxQ.push_back(nums[i]);
            if ((int)window.size() == k) {
                res.push_back(maxQ.front());
                int x = window.front();
                window.pop();
                if (x == maxQ.front()) maxQ.pop_front();
            }
        }
        return res;
    }
};