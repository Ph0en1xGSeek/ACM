class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for (int i = 0; i < nums.size(); ++i) {
            nums_set.insert(nums[i]);
        }
        int ans = 0;
        for (int num : nums_set) {
            if (!nums_set.contains(num - 1)) {
                int tmp = num;
                int cur_ans = 0;
                while(nums_set.contains(tmp)) {
                    ++tmp;
                    ++cur_ans;
                }
                ans = max(ans, cur_ans);
                
            }
        }
        return ans;
    }
};