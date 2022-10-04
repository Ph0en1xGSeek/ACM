class Solution {
public:
    string minWindow(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        if (s_size < t_size) {
            return "";
        }
        int arr[128] = {};
        int cnt = 0;
        for (int i = 0; i < t_size; ++i) {
            if (arr[t[i]] == 0) {
                ++cnt;
            }
            ++arr[t[i]];
        }
        int left = 0;
        int right = 0;
        int min_len = INT_MAX;
        int min_left;
        while (right < s_size) {
            while (right < s_size && cnt > 0) {
                --arr[s[right]];
                if (arr[s[right]] == 0) {
                    --cnt;
                }
                ++right;
            }
            if (right == s_size && cnt > 0) {
                break;
            }
            while (left < right) {
                ++arr[s[left++]];
                if (arr[s[left - 1]] > 0) {
                    ++cnt;
                    break;
                }
            }
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_left = left - 1;
            }
        }
        if (min_len == INT_MAX) {
            return "";
        }
        return s.substr(min_left, min_len);
    }
};