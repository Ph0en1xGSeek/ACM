class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int mx = INT_MIN;
        int mi = INT_MAX;
        unordered_set<int> numsSet;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            if (numsSet.find(nums[i]) != numsSet.end()) {
                return false;
            }
            mx = max(mx, nums[i]);
            mi = min(mi, nums[i]);
            numsSet.insert(nums[i]);
        }
        if (mx < mi + 5) {
            return true;
        }
        return false;
    }
};