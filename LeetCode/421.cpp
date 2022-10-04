class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int mx = 0;
        for(int i = 31; i >= 0; --i) {
            int cur = (1 << i);
            mask |= cur;
            unordered_set<int> st;
            for(int num: nums) {
                st.insert(num & mask);
            }
            int tmp = mx | (1 << i);
            for(auto iter = st.begin(); iter != st.end(); ++iter) {
                if(st.find(*iter ^ tmp) != st.end()) {
                    mx = tmp;
                    break;
                }
            }
        }
        return mx;
    }
};