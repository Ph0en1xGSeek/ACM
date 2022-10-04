class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        cur = mi = prices[0]
        tot = 0
        for i in range(1, len(prices)):
            if prices[i] < prices[i-1]:
                tot += prices[i-1] - mi
                mi = prices[i]
        tot += prices[-1] - mi
        return tot