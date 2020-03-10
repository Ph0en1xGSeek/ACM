class Solution {
public:
	int minSteps(int n) {
		if(n == 1) {
			return 0;
		}
		int d = 2;
		int ans = 0;
		while(n > 1) {
			while(n % d == 0) {
				ans += d;
				n /= d;
			}
			++d;
		}
		return ans;
	}
};
/*
n = n1 * n2
if do not use copy except the first time, n need n times while (n1 * n2) need n1 + n2 times
n1 + n2 <= n1 * n2 when n1 >= 2 and n2 >= 2
so the answer is the sum of all prime factors of n
*/