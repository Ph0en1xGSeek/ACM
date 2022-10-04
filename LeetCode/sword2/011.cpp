class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        unordered_map<int, int> sum_map;
        sum_map[0] = -1;
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                --sum;
            } else {
                ++sum;
            }
            if (sum_map.find(sum) != sum_map.end()) {
                ans = max(ans, i - sum_map[sum]);
            } else {
                sum_map[sum] = i;
            }
        }
        return ans;
    }
};