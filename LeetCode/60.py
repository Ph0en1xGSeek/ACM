class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        arr = [i for i in range(1, n+1)]
        facs = [0]
        ret = ''
        tmp = 1
        for i in range(1, 10):
            tmp *= i
            facs.append(tmp)
        for i in range(n-1, 0, -1):
            iteration = k // facs[i]
            k %= facs[i]
            if k != 0:
                ret += str(arr[iteration])
                arr.pop(iteration)
            else:
                ret += str(arr[iteration-1])
                arr.pop(iteration-1)
        ret += str(arr[0])
        return ret