class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int ans = 0;
        int arr[128] = {};
        int left = 0;
        int right = 0;
        while (right < size) {
            ++arr[s[right]];
            if (arr[s[right]] > 1) {
                while (left < right && arr[s[right]] > 1) {
                    --arr[s[left++]];
                }
            }
            ans = max(ans, right - left + 1);
            ++right;
        }
        ans = max(ans, size - left);
        return ans;
    }
};