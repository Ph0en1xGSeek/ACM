class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        mp = {}
        mx = 0
        left = right = 0
        while right < len(s):
            if (not s[right] in mp) or mp[s[right]] < left:
                mp[s[right]] = right
                right += 1
                mx = max(mx, right-left)
            else:
                left = mp[s[right]] + 1
                mp[s[right]] = right
                right += 1
        return mx



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[128];
        memset(arr, -1, sizeof(arr));
        int size = s.size();
        int ans = 0;
        int left = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[s[i]] >= left) {
                left = arr[s[i]] + 1;
            }
            arr[s[i]] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};