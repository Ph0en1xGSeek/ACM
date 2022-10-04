class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        int sz = tasks.size();
        for(int i = 0; i < sz; ++i) {
            ++cnt[tasks[i] - 'A'];
        }
        sort(cnt.begin(), cnt.end());
        int i = 25;
        while(i >= 0 && cnt[i] == cnt[25]) {
            --i;
        }
        return max(sz, (cnt[25] - 1) * (n + 1) + 25 - i);
    }
};