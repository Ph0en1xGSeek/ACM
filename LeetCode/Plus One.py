class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        jin = 0
        digits[-1] += 1
        if digits[-1] >= 10:
            digits[-1] -= 10
            jin = 1
        for i in range(len(digits)-2, -1, -1):
            digits[i] += jin
            jin = 0
            if digits[i] >= 10:
                jin = 1
                digits[i] -= 10
            else:
                break
        if jin == 1:
            digits.insert(0, 1)
        return digits