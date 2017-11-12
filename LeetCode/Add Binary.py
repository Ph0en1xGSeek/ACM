class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if len(a) == 0:
            return b
        if len(b) == 0:
            return a
        numa = int(a, 2)
        numb = int(b, 2)
        result = numa + numb
        strresult = bin(result)[2:]
        return strresult