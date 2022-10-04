class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int size = p.size();
        int size_s = s.size();
        if (size_s < size) {
            return vector<int>();
        }
        int i;
        int arr[26] = {};
        int cnt = 0;
        vector<int> ans;
        for (i = 0; i < size; ++i) {
            if (arr[p[i] - 'a'] == 0) {
                ++cnt;
            }
            ++arr[p[i] - 'a'];
        }
        for (i = 0; i < size - 1; ++i) {
            if (arr[s[i] - 'a'] == 0) {
                ++cnt;
            }
            --arr[s[i] - 'a'];
            if (arr[s[i] - 'a'] == 0) {
                --cnt;
            }
        }
        for (; i < size_s; ++i) {
            if (arr[s[i] - 'a'] == 0) {
                ++cnt;
            }
            --arr[s[i] - 'a'];
            if (arr[s[i] - 'a'] == 0) {
                --cnt;
            }
            if (cnt == 0) {
                ans.push_back(i - size + 1);
            }
            if (arr[s[i - size + 1] - 'a'] == 0) {
                ++cnt;
            }
            ++arr[s[i - size + 1] - 'a'];
            if (arr[s[i - size + 1] - 'a'] == 0) {
                --cnt;
            }
        }
        return ans;
    }
};