class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[128] = {0};
        int size = s.length();
        int ans = 0;
        int left = 0, right = 0;
        while(right < size) {
            ++cnt[s[right]];
            if (cnt[s[right]] > 1) {
                while(left < right && cnt[s[right]] > 1) {
                    --cnt[s[left]];
                    ++left;
                }
            }
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;
    }
};