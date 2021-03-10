class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int sz = nums.size();
        if(sz == 0) {
            return false;
        }
        unordered_set<int> st;
        for(int i = 0; i < sz; ++i) {
            if(st.find(nums[i]) != st.end()) {
                return true;
            }
            if(i - k >= 0) {
                auto iter = st.find(nums[i-k]);
                st.erase(iter);
            }
            st.insert(nums[i]);
        }
        return false;
    }
};