class Solution {
public:
	bool dfs(int target, vector<int> &nums, vector<int> &cnt, int pos) {
		if(pos == nums.size()) {
			for(int i = 0; i < 4; ++i) {
				if(cnt[i] != target) {
					return false;
				}
			}
			return true;
		}
		for(int i = 0; i < 4; ++i) {
			if(cnt[i] + nums[pos] <= target) {
				cnt[i] += nums[pos];
				if(dfs(target, nums, cnt, pos+1)) {
					return true;
				}
				cnt[i] -= nums[pos];
			}
		}
		return false;
	}

	bool makesquare(vector<int> &nums) {
		int sz = nums.size();
		if(sz < 4) {
			return false;
		}
		int sum = 0;
		for(int i = 0; i < sz; ++i) {
			sum += nums[i];
		}
		int target = sum / 4;
		if(sum % 4 != 0) {
			return false;
		}
		vector<int> cnt(4, 0);
		sort(nums.begin(), nums.end(), greater<int>());
		return dfs(target, nums, cnt, 0);
	}
};
