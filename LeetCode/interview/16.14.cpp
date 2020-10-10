class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    vector<int> bestLine(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        unordered_map<int, pair<int, int> > ret_mp;
        vector<int> ret;
        int size = points.size();
        if(size < 2) {
            return ret;
        }
        ret.resize(2);
        int ans = 0;
        int tmp = 0;
        int cnt = 0;
        int inf_cnt = 0;
        pair<int, int> inf_pair;
        for(int i = 0; i < size; ++i) {
            mp.clear();
            ret_mp.clear();
            cnt = inf_cnt = 0;
            for(int j = i + 1; j < size; ++j) {
                int y = points[j][1] - points[i][1];
                int x = points[j][0] - points[i][0];
                if(x == 0) {
                    if(y == 0) {
                        ++cnt;
                    }else {
                        ++inf_cnt;
                        if(inf_cnt == 1) {
                            inf_pair = {i, j};
                        }
                    }
                    continue;
                }
                int g = gcd(x, y);
                x /= g;
                y /= g;
                cout << i << " " << j << " " << x << " " << y << endl;
                ++mp[(x * 10000) + y];
                if(ret_mp.find((x * 10000) + y) == ret_mp.end()) {
                    ret_mp[(x * 10000) + y] = {i, j};
                }
            }
            for(auto item: mp) {
                if(item.second + 1 + cnt > ans) {
                    ans = item.second + 1 + cnt;
                    ret[0] = ret_mp[item.first].first;
                    ret[1] = ret_mp[item.first].second;
                }else if(item.second + 1 + cnt == ans) {
                    if(ret_mp[item.first].first < ret[0] || (ret_mp[item.first].first == ret[0] && ret_mp[item.first].second < ret[1])) {
                        ret[0] = ret_mp[item.first].first;
                        ret[1] = ret_mp[item.first].second;
                    }
                }
            }
            if(inf_cnt + 1 + cnt > ans) {
                ans = inf_cnt + 1 + cnt;
                ret[0] = inf_pair.first;
                ret[1] = inf_pair.second;
            }
        }
        return ret;
    }
};