class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        ge = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
        shi = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
        bai = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
        qian = ['', 'M', 'MM', 'MMM']
        
        str = ''
        cnt = 0
        while num > 0:
            tmp = num % 10
            num //= 10
            if cnt == 0:
                str = ge[tmp]
            elif cnt == 1:
                str = shi[tmp] + str
            elif cnt == 2:
                str = bai[tmp] + str
            else:
                str = qian[tmp] + str
            
            cnt += 1
        return str