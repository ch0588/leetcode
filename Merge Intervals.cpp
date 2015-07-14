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
    bool static cmp(Interval a,Interval b){
        if(a.start==b.start) return a.end<b.end;
        return a.start<b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {

        vector<Interval>ans;
        ans.clear();

        if((int)intervals.size()==0) return ans;

        sort(intervals.begin(),intervals.end(),cmp);
        int l=intervals[0].start, r=intervals[0].end;
        for(int i=1; i<(int)intervals.size(); ++i){
            if(intervals[i].start<=r){
                r = max(r,intervals[i].end);
            }
            else{
                ans.push_back( Interval(l,r) );
                l=intervals[i].start, r=intervals[i].end;
            }
        }
        ans.push_back( Interval(l,r) );
        return ans;
    }
};
