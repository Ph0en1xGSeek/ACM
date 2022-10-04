class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		int sz = nums.size();
		vector<vector<int>> ans;
		ans.push_back(vector<int>());
		if(sz == 0) {
			return ans;
		}
		int pre_pos = 0;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < sz; ++i) {
            int ans_sz = ans.size();
			if(i == 0 || nums[i] != nums[i-1]) {
                pre_pos = ans_sz - 1;
				for(int j = 0; j <= pre_pos; ++j) {
					ans.push_back(ans[j]);
					ans.back().push_back(nums[i]);
				}
			}else {
				for(int j = pre_pos+1; j < ans_sz; ++j) {
					ans.push_back(ans[j]);
					ans.back().push_back(nums[i]);
				}
                pre_pos = ans_sz - 1;
			}
		}
		return ans;
	}
};