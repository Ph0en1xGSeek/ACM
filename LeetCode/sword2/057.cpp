class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        set<int> recent;
        for (int i = 0; i < size; ++i) {
            set<int>::iterator iter = recent.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (iter != recent.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }
            recent.insert(nums[i]);
            if (i >= k) {
                recent.erase(nums[i - k]);
            }
        }
        return false;
    }
};


class Solution {
public:
    int getBucket(int num, int w) {
        return num < 0 ? (num + 1LL) / w - 1 : num / w;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < size; ++i) {
            int bucket = getBucket(nums[i], t + 1LL);
            if (mp.find(bucket) != mp.end()) {
                return true;
            }
            if (mp.find(bucket - 1) != mp.end() && mp[bucket - 1] >= nums[i] - t) {
                return true;
            }
            if (mp.find(bucket + 1) != mp.end() && mp[bucket + 1] <= nums[i] + t) {
                return true;
            }
            mp[bucket] = nums[i];
            if (i >= k) {
                mp.erase(getBucket(nums[i - k], t + 1LL));
            }
        }
        return false;
    }
};