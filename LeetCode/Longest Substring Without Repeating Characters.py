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