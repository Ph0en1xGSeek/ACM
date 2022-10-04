class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int sum = 3;
        int left = 1, right = 2;
        while (left < right && left <= (target >> 1)) {
            if (sum == target) {
                vector<int> tmp;
                for (int i = left; i <= right; ++i) {
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                ++right;
                sum += right;
                sum -= left;
                ++left;
            } else if (sum > target) {
                sum -= left;
                ++left;
            }  else {
                ++right;
                sum += right;
            }
        }
        return res;
    }
};