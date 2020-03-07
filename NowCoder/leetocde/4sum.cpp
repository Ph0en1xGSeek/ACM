class Solution {
public:
	vector<vector<int>> fourSum(vector<int> &nums, int target) {
		int sz = nums.size();
		vector<vector<int> > ans;
		if(sz < 4) {
			return ans;
		}
		sort(nums.begin(), nums.end());
		for(int i = 0; i < sz; ++i) {
			while(i != 0 && i < sz-3 && nums[i-1] == nums[i]) {
				++i;
			}
			if(i < sz && nums[i] * 4 > target) {
				break;
			}
			for(int j = i+1; j < sz-2; ++j) {
				while(j != i + 1 && j < sz && nums[j-1] == nums[j]) {
					++j;
				}
				int cur_sum = nums[i] + nums[j];
				if(cur_sum * 2 > target) {
					break;
				}
				int left = j+1;
				int right = sz - 1;
				while(left < right) {
					if(cur_sum + nums[left] + nums[right] == target) {
						ans.push_back({nums[i], nums[j], nums[left], nums[right]});
						++left;
						--right;
					while(left < right && nums[left] == nums[left-1]) {
						++left;
					}
					while(left < right && nums[right] == nums[right+1]) {
						--right;
					}
					}else if(cur_sum + nums[left] + nums[right] > target) {
						--right;
					}else {
						++left;
					}

				}
			}
		}
		return ans;
	}
};
