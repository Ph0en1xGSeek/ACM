class Solution {
public:
	int minCostClimbingStairs(vector<int> &cost) {
		int size = cost.size();
		int cur = 0, pre = 0, pre_pre = 0;
		for(int i = 2; i <= size; ++i) {
			pre_pre = pre;
			pre = cur;
			cur = min(pre_pre + cost[i-2], pre + cost[i-1]);
		}
		return cur;
 	}
};
