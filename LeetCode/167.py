class Solution(object):
    def bisearch(self, numbers, l, r, n):
        while(l <= r):
            mid = (l+r)>>1
            if numbers[mid] > n:
                r = mid - 1
            elif numbers[mid] < n:
                l = mid + 1
            else:
                return mid
        return -1
    
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(numbers) < 2:
            return None
        l = 0
        r = len(numbers) - 1
        while(l < r):
            if numbers[l] + numbers[r] > target:
                r -= 1
            elif numbers[l] + numbers[r] < target:
                l += 1
            else:
                return [l+1, r+1]
        return None
        # for i in range(len(numbers) - 1):
        #     if numbers[i] > target:
        #         break
        #     res = self.bisearch(numbers, i+1, len(numbers)-1, target - numbers[i])
        #     if res > 0:
        #         return [i+1, res+1]
        # return None