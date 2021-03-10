class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sz = nums.size();
        int sum = 0;
        int ans = 0;
        mp[0] = 1;
        for(int i = 0; i < sz; ++i) {
            sum += nums[i];
            int target = sum - k;
            if(mp.find(target) != mp.end()) {
                ans += mp[target];
            }
            ++mp[sum];
        }
        return ans;
    }
};