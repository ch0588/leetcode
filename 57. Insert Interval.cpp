// Time Complexity: O(n)
// Space Complexity: O(1)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size();
        int i = 0;
        while (i <n && intervals[i].end < newInterval.start)
            res.emplace_back(intervals[i++]);
        
        if (i >= n) { //newInterval at the last pos
            res.emplace_back(newInterval);
            return res;
        }
        int start = min(intervals[i].start, newInterval.start);
        int end = newInterval.end;
        while (i < n && intervals[i].start <= newInterval.end) {
            end = max(intervals[i].end, newInterval.end);
            i++;
        }
        res.emplace_back(Interval(start,end));
        
        while (i < n)
            res.emplace_back(intervals[i++]);
        
        return res;
    }
};
