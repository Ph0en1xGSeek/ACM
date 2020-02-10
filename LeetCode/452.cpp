class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int sz = points.size();
        if(sz == 0) {
            return 0;
        }
        sort(points.begin(), points.end());
        int cur_start = points[0][0];
        int cur_end = points[0][1];
        int cnt = 0;
        for(int i = 1; i < sz; ++i) {
            if(points[i][0] > cur_end) {
                ++cnt;
                cur_start = points[i][0];
                cur_end = points[i][1];
            }else {
                cur_start = max(cur_start, points[i][0]);
                cur_end = min(cur_end, points[i][1]);
            }
        }
        return ++cnt;
    }
};