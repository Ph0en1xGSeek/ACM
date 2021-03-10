class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k == 0)
            return false;
        multiset<long long> st;
        for(int i = 0; i < nums.size(); i++){
            multiset<long long>::iterator iter = st.lower_bound((long long)nums[i] - (long long)t);
            if(iter != st.end() && abs((*iter) - (long long)nums[i]) <= t)
                return true;
            st.insert(nums[i]);
            if(i - k >= 0)
                st.erase(st.find(nums[i-k]));
        }
        return false;
    }
};