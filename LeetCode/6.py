class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or numRows == 0:
            return s
        arr = [''] * numRows
        for i in range(len(s)):
            if i % (numRows * 2 - 2) < numRows:
                arr[i%(numRows*2-2)] += s[i]
            else:
                arr[2*(numRows-1) - (i%(numRows*2-2))] += s[i]
        str = ''
        for i in range(numRows):
            str += arr[i]
        return str