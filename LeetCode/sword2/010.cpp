class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt_map;
        cnt_map[0] = 1;
        int size = nums.size();
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            if (cnt_map.find(sum - k) != cnt_map.end()) {
                ans += cnt_map[sum - k];
            }
            cnt_map[sum]++;
        }
        return ans;
    }
};