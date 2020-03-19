class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        a = abs(dividend)
        b = abs(divisor)
        arr = []
        while(b <= a):
            arr.append(b)
            b <<= 1
        sum = 0
        ret = 0
        for i in range(len(arr)-1, -1, -1):
            if sum + arr[i] <= a:
                sum += arr[i]
                ret += (1<<i)
        if(((dividend > 0) and (divisor < 0)) or ((dividend < 0) and (divisor > 0))):
            return -ret
        else:
            return ret

class Solution {
public:
	int divide(int dividend, int divisor) {
		if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
			return INT_MAX;
		}
		bool flag = (dividend < 0) ^ (divisor < 0);
		long long divisor_long = labs(divisor);
		long long dividend_long = labs(dividend);
		vector<long long> arr;
		while(divisor_long > 0 && divisor_long <= dividend_long) {
			arr.push_back(divisor_long);
			divisor_long <<= 1;
		}
		int size = arr.size();
		long long tmp = (size == 0? 0: 1 << (size-1));
		long long ans = 0;
		for(int i = size - 1; i >= 0; --i) {
			while(dividend_long >= arr[i]) {
				dividend_long -= arr[i];
				ans += tmp;
			}
			tmp >>= 1;
		}
        if(flag)
            ans = -ans;
		return (int)ans;
	}
};