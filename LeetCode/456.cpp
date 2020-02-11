class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 3) {
            return false;
        }
        stack<int> st;
        int ak = INT_MIN;
        st.push(nums[sz-1]);
        for(int i = sz-1; i >= 0; --i) {
            if(nums[i] < ak) {
                return true;
            }
            while(!st.empty() && nums[i] > st.top()) {
                ak = max(ak, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};