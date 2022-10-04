class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> st;
        int size = nums.size();
        for(int i = 0; i < size; ++i) {
            if(st.find(nums[i]) != st.end()) {
                return nums[i];
            }else {
                st.insert(nums[i]);
            }
        }
        return -1;
    }
};