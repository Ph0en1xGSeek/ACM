class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size_1 = s1.size();
        if (size_1 > s2.size()) {
            return false;
        }
        int s1_cnt[26] = {};
        int cnt = 0;
        for (int i = 0; i < size_1; ++i) {
            if (s1_cnt[s1[i] - 'a'] == 0) {
                ++cnt;
            }
            ++s1_cnt[s1[i] - 'a'];
        }
        int i;
        for (i = 0; i < size_1 - 1; ++i) {
            if (s1_cnt[s2[i] - 'a'] == 0) {
                ++cnt;
            }
            --s1_cnt[s2[i] - 'a'];
            if (s1_cnt[s2[i] - 'a'] == 0) {
                --cnt;
            }
        }
        for (; i < s2.size(); ++i) {
            if (s1_cnt[s2[i] - 'a'] == 0) {
                ++cnt;
            }

            --s1_cnt[s2[i] - 'a'];
            if (s1_cnt[s2[i] - 'a'] == 0) {
                --cnt;
            }

            if (cnt == 0) {
                return true;
            }

            if (s1_cnt[s2[i - size_1 + 1] - 'a'] == 0) {
                ++cnt;
            }
            ++s1_cnt[s2[i - size_1 + 1] - 'a'];
            if (s1_cnt[s2[i - size_1 + 1] - 'a'] == 0) {
                --cnt;
            }

        }
        return false;
    }
};