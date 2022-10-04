class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        length = len(height)
        if height == None or length == 0:
            return 0
        
        l = 0
        r = length - 1
        result = 0
        
        maxL = maxR = 0
        
        while l <= r:
            maxL = max(height[l], maxL)
            maxR = max(height[r], maxR)
            
            if maxL < maxR:
                result += maxL - height[l]
                l += 1
            else:
                result += maxR - height[r]
                r -= 1
        return result