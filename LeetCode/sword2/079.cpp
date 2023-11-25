class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << size); ++i) {
            vector<int> result;
            for (int j = 0; j < size; ++j) {
                if (i & (1 << j)) {
                    result.push_back(nums[j]);
                }
            }
            ans.push_back(result);
        }
        return ans;
    }
};