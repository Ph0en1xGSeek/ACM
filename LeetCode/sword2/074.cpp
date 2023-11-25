class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < size; ++i) {
            vector<int> &interval = intervals[i];
            if (interval[0] > right) {
                ans.push_back({left, right});
                left = interval[0];
                right = interval[1];
            } else {
                right = max(right, interval[1]);
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};