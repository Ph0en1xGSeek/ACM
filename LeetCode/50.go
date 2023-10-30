func quickMul(x float64, n int) float64 {
    ans := 1.0
    tmp := x
    for n > 0 {
        if (n & 1) == 1 {
            ans *= tmp
        }
        tmp *= tmp
        n >>= 1
    }
    return ans
}

func myPow(x float64, n int) float64 {
    if n >= 0 {
        return quickMul(x, n);
    } else {
        return 1.0 / quickMul(x, -n);
    }
}

class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        flag = False
        if(n < 0):
            n = -n
            flag = True
        
        res = 1.0
        while(n > 0):
            if(n & 1 == 1):
                res *= x
            x *= x
            n >>= 1

        if flag:
            res = 1.0 / res
        
        return res