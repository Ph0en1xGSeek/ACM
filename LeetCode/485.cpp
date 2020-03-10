class Solution {
public:
	int findMaxConsecutiveOnes(vector<int> &nums) {
		int cur_cnt = 0;
		int mx_cnt = 0;
		int sz = nums.size();
		if(sz == 0) {
			return 0;
		}
		for(int i = 0; i < sz; ++i) {
			if(nums[i] == 1) {
				++cur_cnt;
			}else {
				mx_cnt = max(mx_cnt, cur_cnt);
				cur_cnt = 0;
			}
		}
		mx_cnt = max(mx_cnt, cur_cnt);
		return mx_cnt;
	}
};
