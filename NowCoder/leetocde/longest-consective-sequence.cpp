class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> mp;
        int sz = num.size();
        if(sz == 0) {
            return 0;
        }
        for(int i = 0; i < sz; ++i) {
            if(mp.find(num[i]) != mp.end()) {
                continue;
            }
            int dir = 0;
            if(mp.find(num[i] + 1) != mp.end()) {
                dir |= 1;
                mp[num[i] + 1] |= 2;
            }
            if(mp.find(num[i] - 1) != mp.end()) {
                dir |= 2;
                mp[num[i] - 1] |= 1;
            }
            mp[num[i]] = dir;
        }
        int mx = 1;
        int cnt = 0;
        int cur;
        for(int i = 0; i < sz; ++i) {
            if(mp[num[i]] == 1) {
                cnt = 0;
                cur = num[i];
                while(mp[cur] != 0) {
                    ++cur;
                    ++cnt;
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};



class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> mp;
        int sz = num.size();
        if(sz == 0) {
            return 0;
        }
        int ans = 1;
        for(int i = 0; i < sz; ++i) {
            if(mp.find(num[i]) != mp.end()) {
                continue;
            }
            int left = mp.find(num[i] - 1) == mp.end() ? 0 : mp[num[i] - 1];
            int right = mp.find(num[i] + 1) == mp.end() ? 0 : mp[num[i] + 1];
            mp[num[i]] = left + right + 1;
            mp[num[i] - left] = mp[num[i]];
            mp[num[i] + right] = mp[num[i]];
            ans = max(ans, mp[num[i]]);
        }
        return ans;
    }
};