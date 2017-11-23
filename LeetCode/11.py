class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        mx = 0
        i = 0
        j = len(height) - 1
        while i < j:
            v = min(height[i], height[j]) * (j-i)
            mx = max(mx, v)
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return mx