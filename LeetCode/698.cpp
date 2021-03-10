class Solution {
	bool dfs(vector<int> &nums, int k, int cur, int target, int start, vector<bool> &visited) {
		if(k == 1) {
			return true;
		}
		if(cur == target) {
			return dfs(nums, k-1, 0, target, 0, visited);
		}
        if(cur > target) {
            return false;
        }
		for(int i = start; i < nums.size(); ++i) {
			if(!visited[i]) {
				visited[i] = true;
				if(dfs(nums, k, cur + nums[i], target, start + 1, visited)) {
					return true;
				}
				visited[i] = false;
			}
		}
		return false;
	}
public:
	bool canPartitionKSubsets(vector<int> &nums, int k) {
		int size = nums.size();
		if(size == 0) {
			return false;
		}
        sort(nums.begin(), nums.end(), greater<int>());
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum % k != 0) {
			return false;
		}
        if(nums[0] > sum / k) {
            return false;
        }
		vector<bool> visited(size, false);
		return dfs(nums, k, 0, sum / k, 0, visited);
	}
};
