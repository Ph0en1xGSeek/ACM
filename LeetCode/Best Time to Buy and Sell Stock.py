class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        mi = prices[0]
        mx = 0
        for i in range(len(prices)):
            mi = min(mi, prices[i])
            mx = max(mx, prices[i] - mi)
        return mx