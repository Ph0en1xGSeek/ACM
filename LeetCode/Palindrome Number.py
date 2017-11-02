class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        arr = str(x)
        rev = reversed(arr)
        for i in range(len(arr)):
            if arr[i] != arr[len(arr)-1-i]:
                return False
        return True
        