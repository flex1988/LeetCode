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
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;

        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) { return a.start < b.start; });

        for (int i = 0; i < intervals.size(); i++) {
            if (ret.size() == 0) {
                ret.push_back(intervals[i]);
            } else {
                if (ret.back().end < intervals[i].start) {
                    ret.push_back(intervals[i]);
                } else {
                    if (ret.back().end < intervals[i].end) {
                        ret.back().end = intervals[i].end;
                    }
                }
            }
        }

        return ret;
    }
};
