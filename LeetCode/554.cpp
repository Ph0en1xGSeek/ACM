class Solution {
public:

    int leastBricks(vector<vector<int>>& wall) {
        int size = wall.size();
        if(size == 0) {
            return 0;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> nex_pos(size, 1);
        for(int i = 0; i < size; ++i) {
            q.push(make_pair(wall[i][0], i));
        }
        int sum = accumulate(wall[0].begin(), wall[0].end(), 0);
        int ans = 0;
        int cnt = 0;
        while(true) {
            int cur = q.top().first;
            if(cur == sum) {
                break;
            }
            cnt = 0;
            while(q.top().first == cur) {
                ++cnt;
                auto tp = q.top();
                q.pop();
                q.push(make_pair(tp.first + wall[tp.second][nex_pos[tp.second]], tp.second));
                ++nex_pos[tp.second];
            }
            ans = max(cnt, ans);
        }
        return size - ans;
    }
};



class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        int size = wall.size();
        if(size == 0) {
            return 0;
        }
        unordered_map<int, int> mp;
        int sum = 0;
        for(int i = 0; i < size; ++i) {
            sum = 0;
            for(int j = 0; j < wall[i].size() - 1; ++j) {
                sum += wall[i][j];
                ++mp[sum];
            }
        }
        int ans = 0;
        for(auto iter = mp.begin(); iter != mp.end(); ++iter) {
            ans = max(ans, iter->second);
        }
        return size - ans;
	}
};
