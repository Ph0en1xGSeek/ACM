class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        int sz = T.size();
        if(sz == 0) {
            return vector<int>();
        }
        vector<int> res(sz);
        for(int i = sz - 1; i >= 0; --i) {
            while(!st.empty() && T[i] >= T[st.top()]) st.pop();
            if(st.empty()) {
                res[i] = 0;
            }else {
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};