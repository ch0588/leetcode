/*
 Given an array of meeting time intervals consisting of start and end times
 [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
 required.
 
 For example,
 Given [[0, 30],[5, 10],[15, 20]],
 return 2.
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
    int minMeetingRooms(vector<Interval>& intervals) {
        // start 2*i even
        // end 2*i-1 odd
        vector<int> a;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            int s = 2 * intervals[i].start;
            int e = 2 * intervals[i].end - 1;
            a.push_back(s);
            a.push_back(e);
        }
        sort(a.begin(), a.end());
        
        int m = a.size();
        int res = 0, cur = 0;
        for (int i = 0; i < m; ++i) {
            if ((a[i] & 1) == 0) {
                cur++;
                res = max(res, cur);
            } else {
                cur--;
            }
        }
        return res;
    }
};