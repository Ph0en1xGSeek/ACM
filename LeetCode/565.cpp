class Solution {
public:
	int arrayNesting(vector<int> &nums) {
		int size = nums.size();
		if(size == 0) {
			return 0;
		}
		int ans = 0;
		int cnt = 0;
		int pos;
		for(int i = 0; i < size; ++i) {
			if(nums[i] >= size) {
				continue;
			}
			cnt = 0;
			pos = i;
			while(nums[pos] < size) {
				++cnt;
				nums[pos] += size;
				pos = nums[pos] - size;
			}
			ans = max(ans, cnt);
		}
		return ans;
	}
};