class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < size; ++i) {
            if(nums[i] == 1) {
                ++sum;
            }else {
                --sum;
            }
            if(mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            }else {
                mp[sum] = i;
            }
        }
        return ans;
    }
};