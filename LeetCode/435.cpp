class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        if(sz == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int cnt = 0;
        int pos1 = -1, pos2 = 0;
        while(pos2 < sz) {
            while(pos2 < sz-1 && intervals[pos2][0] == intervals[pos2+1][0]) {
                ++pos2;
                ++cnt;
            }
            if(pos1 < 0) {
                pos1 = pos2;
                ++pos2;
            }else {
                if(intervals[pos1][1] <= intervals[pos2][0]) {
                    pos1 = pos2;
                    ++pos2;
                }else if(intervals[pos1][1] > intervals[pos2][1]) {
                    pos1 = pos2;
                    ++pos2;
                    ++cnt;
                }else {
                    ++pos2;
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};