class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int sz = points.size();
        if(sz < 3) {
            return 0;
        }
        int ans = 0;
        for(int i = 0; i < sz; ++i) {
            unordered_map<int, int> mp;
            for(int j = 0; j < sz; ++j) {
                int dis = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                ++mp[dis];
            }
            for(auto iter = mp.begin(); iter != mp.end(); ++iter) {
                int cnt = (*iter).second;
                ans += cnt * (cnt - 1);
            }
        }
        return ans;
    }
};