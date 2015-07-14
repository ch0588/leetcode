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
        vector<Interval>ret;
        int i = 0;
        while(i<intervals.size() && intervals[i].end<newInterval.start)
            ret.push_back(intervals[i++]);

        if(i>=intervals.size()){ //newInterval at the last pos
            ret.push_back(newInterval);
            return ret;
        }
        int start = min(intervals[i].start,newInterval.start);
        int end = newInterval.end;
        while(i<intervals.size() && intervals[i].start<=newInterval.end) {
            end = max(intervals[i].end,newInterval.end);
            i++;
        }
        ret.push_back(Interval(start,end));

        while(i<intervals.size())
            ret.push_back(intervals[i++]);

        return ret;
    }
};
