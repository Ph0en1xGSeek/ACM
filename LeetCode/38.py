class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        arr = ['']
        arr[0] = '1'
        for i in range(1,n):
            arr.append('')
            pre = arr[i-1][0]
            cnt = 1
            for j in range(1, len(arr[i-1])):
                if arr[i-1][j] != pre:
                    arr[i] += (str(cnt) + pre)
                    pre = arr[i-1][j]
                    cnt = 1
                else:
                    cnt += 1
            arr[i] += (str(cnt) + pre)
        return arr[n-1]