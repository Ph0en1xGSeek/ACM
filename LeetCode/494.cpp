class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sz = nums.size();
        for(int i = 0; i < sz; ++i) {
            unordered_map<int, int> tmp;
            for(auto p: mp) {
                int cur_sum = p.first;
                int cur_cnt = p.second;
                tmp[cur_sum + nums[i]] += cur_cnt;
                tmp[cur_sum - nums[i]] += cur_cnt;
            }
            mp = tmp;
        }
        return mp[S];
    }
};