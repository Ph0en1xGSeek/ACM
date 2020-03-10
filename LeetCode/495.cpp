class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sz = timeSeries.size();
        if(sz == 0) {
            return 0;
        }
        int ans = 0;
        int left = timeSeries[0], right = timeSeries[0] + duration;
        for(int i = 1; i < sz; ++i) {
            if(timeSeries[i] > right) {
                ans += right - left;
                left = timeSeries[i];
                right = timeSeries[i] + duration;
            }else {
                right = timeSeries[i] + duration;
            }
        }
        ans += right - left;
        return ans;
    }
};