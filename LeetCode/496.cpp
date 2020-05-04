class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int size = nums1.size();
        for(int i = 0; i < size; ++i) {
            mp[nums1[i]] = i;
        }
        vector<int> ans(size);
        stack<int> st;
        for(int i = nums2.size()-1; i >= 0; --i) {
            while(!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }
            if(mp.find(nums2[i]) != mp.end()) {
                if(st.empty())
                    ans[mp[nums2[i]]] = -1;
                else
                    ans[mp[nums2[i]]] = st.top();
            }
            st.push(nums2[i]);
        }
        return ans;
    }
};