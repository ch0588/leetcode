/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
*/


// Time Complexity: O(nlogn)
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
    static bool cmp(Interval a, Interval b) {
        if (a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return true;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int pre_end = intervals[0].start;
        for (int i = 0; i < n; ++i) {
            if (pre_end > intervals[i].start) return false;
            pre_end = intervals[i].end;
        }
        return true;
    }
};