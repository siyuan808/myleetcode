class Solution {
    bool compare(Interval a, Interval b) {
	return a.start - b.start;
    }
    class Comp {
    public:
        bool operator() (const Interval& a, const Interval & b){
	    return a.start < b.start;
	}
    };

    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() <= 1) return intervals;
	sort(intervals.begin(), intervals.end(), Comp());
	vector<Interval> res;
	res.push_back(intervals[0]);
	for(int i=1; i<intervals.size(); i++) {
	    if(intervals[i].start <= res.back().end) {
		Interval interval(res.back().start, max(res.back().end, intervals[i].end));
		res.pop_back();
		res.push_back(interval);
	    } else {
		res.push_back(intervals[i]);
	    }
	}
	return res;
    }
};
