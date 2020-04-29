class Solution {
private:
	int size;
public:
	void dfs(vector<int> &nums,  int pos, vector<vector<int>> &ans, vector<int> &cur) {
		if(pos == size) {
            if(cur.size() >= 2)
			    ans.push_back(cur);
			return;
		}
        unordered_set<int> st;
		for(int i = pos + 1; i <= size; ++i) {
			if(i == size) {
				dfs(nums, i, ans, cur);
				return;
			}
            if(pos != -1 && nums[i] < nums[pos]) {
                continue;
            }
			if(st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
			}else {
                continue;
            }
			cur.push_back(nums[i]);
			dfs(nums, i, ans, cur);
			cur.pop_back();
		}
	}

	vector<vector<int>> findSubsequences(vector<int> &nums) {
		size = nums.size();
		vector<vector<int>> ans;
		if(size == 0) {
			return ans;
		}
		vector<int> cur;
		dfs(nums, -1, ans, cur);
		return ans;
	}
};
