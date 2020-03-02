class Solution {
public:
	int climbStairs(int n) {
		if(n <= 1) {
			return 1;
		}
		int pre_pre = 0, pre = 1, cur = 1;
		for(int i = 2; i <= n; ++i) {
			pre_pre = pre;
			pre = cur;
			cur = pre_pre + pre;
		}
		return cur;
	}
};
