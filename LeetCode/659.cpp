class Solution {
public:
	bool isPossible(vector<int> &nums) {
		int size = nums.size();
		if(size < 3) {
			return false;
		}
		unordered_map<int, int> cnt;
		unordered_map<int, int> next;
		for(int i = 0; i < size; ++i) {
			++cnt[nums[i]];
		}
		for(int i = 0; i < size; ++i) {
			if(cnt[nums[i]] == 0) {
				continue;
			}
			if(next[nums[i]] > 0) {
				++next[nums[i] + 1];
				--next[nums[i]];
				--cnt[nums[i]];
			}else if(cnt[nums[i] + 1] > 0 && cnt[nums[i] + 2] > 0) {
				--cnt[nums[i]];
				--cnt[nums[i] + 1];
				--cnt[nums[i] + 2];
				++next[nums[i] + 3];
			}else {
				return false;
			}
		}
		return true;
 	}
};
