class Solution {
public:
	int smallestRepunitDivByK(int K) {
		int num = 1;
		for(int i = 1; i <= K; ++i) {
			if(num % K == 0) {
				return i;
			}
			num = (num * 10 + 1) % K;
		}
		return -1;
	}
};