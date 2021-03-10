class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> right(size, -1);
        stack<int> st;
        for(int i = size-1; i >= 0; --i) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                right[i] = st.top();
            }
            st.push(nums[i]);
        }
        for(int i = size-1; i >= 0; --i) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if(right[i] == -1 && !st.empty()) {
                right[i] = st.top();
            }
            st.push(nums[i]);
        }
        return right;
    }
};