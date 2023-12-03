class Solution {
public:
    vector<int> maxAltitude(vector<int>& heights, int limit) {
        int size = heights.size();
        if (size == 0 || limit == 0) {
            return {};
        }
        deque<int> dq;
        for (int i = 0; i < limit - 1; ++i) {
            while (!dq.empty() && heights[dq.back()] < heights[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> ans;
        for (int i = limit - 1; i < size; ++i) {
            while (!dq.empty() && heights[dq.back()] < heights[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() <= i - limit) {
                dq.pop_front();
            }
            ans.push_back(heights[dq.front()]);
        }
        return ans;
    }
};