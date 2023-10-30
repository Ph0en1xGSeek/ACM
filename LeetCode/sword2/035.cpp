class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int size = timePoints.size();
        if (size < 2 || size > 1440) {
            return 0;
        }
        vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = convert(timePoints[i]);
        }
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        for (int i = 0; i < size - 1; ++i) {
            ans = min(ans, arr[i + 1] - arr[i]);
        }
        ans = min(ans, arr[0] + 1440 - arr.back());
        return ans;
    }

    inline int convert(string &timePoint) {
        return ((timePoint[0] - '0') * 10 + (timePoint[1] - '0')) * 60 + ((timePoint[3] - '0') * 10 + (timePoint[4] - '0'));
    }
};