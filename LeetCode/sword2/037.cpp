class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size = asteroids.size();
        vector<int> ans;
        if (size == 0) {
            return ans;
        }
        int pos = 0;
        for (pos = 0; pos < size; ++pos) {
            if (asteroids[pos] < 0) {
                ans.push_back(asteroids[pos]);
            } else {
                break;
            }
        }
        for (int i = pos; i < size; ++i) {
            if (asteroids[i] > 0) {
                ans.push_back(asteroids[i]);
            } else {
                while (!ans.empty() && ans.back() > 0 && -ans.back() > asteroids[i]) {
                    ans.pop_back();
                }
                if (!ans.empty() && ans.back() > 0) {
                    if (-ans.back() == asteroids[i]) {
                        ans.pop_back();
                    }
                } else {
                    ans.push_back(asteroids[i]);
                }
            }
        }
        return ans;
    }
};