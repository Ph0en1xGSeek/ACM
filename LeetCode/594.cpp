class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int item: nums) {
            ++mp[item];
        }
        int ans = 0;
        for(auto item: mp) {
            int key = item.first;
            if(mp.find(key + 1) != mp.end())
                ans = max(ans, mp[key] + mp[key + 1]);
        }
        return ans;
    }
};