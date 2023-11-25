class Solution {
public:
    bool validateBookSequences(vector<int>& putIn, vector<int>& takeOut) {
        int size = putIn.size();
        stack<int> st;
        int pos = 0;
        for (int i = 0; i < size; ++i) {
            if (!st.empty() && st.top() == takeOut[i]) {
                st.pop();
            } else {
                while (pos < size && putIn[pos] != takeOut[i]) {
                    st.push(putIn[pos++]);
                }
                if (pos < size) {
                    ++pos;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};