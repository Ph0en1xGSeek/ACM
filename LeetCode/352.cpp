class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        vector<int> newInterval({val, val});
        int overlap = 0, i;
        for(i = 0; i < intervals.size(); ++i) {
            if(newInterval[1] + 1 < intervals[i][0]) {
                break;
            }
            if(newInterval[0] <= intervals[i][1] + 1) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                ++overlap;
            }
        }
        if(overlap != 0) {
            intervals.erase(intervals.begin() + i - overlap, intervals.begin() + i);
        }
        intervals.insert(intervals.begin() + i - overlap, newInterval);
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
private:
    vector<vector<int>>  intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */