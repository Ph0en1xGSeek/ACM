class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].length();
        if (m == 0) {
            return 0;
        }
        vector<int> height(m, 0);
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            stack<int> st;
            vector<int> left(m);
            vector<int> right(m, m);
            int row_ans = INT_MIN;
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                } else {
                    height[j] = 0;
                }
                while (!st.empty() && height[st.top()] >= height[j]) {
                    right[st.top()] = j;
                    st.pop();
                }
                left[j] = st.empty() ? -1 : st.top();
                st.push(j);
            }
            for (int j = 0; j < m; ++j) {
                row_ans = max(row_ans, height[j] * (right[j] - left[j] - 1));
            }
            ans = max(ans, row_ans);
        }
        return ans;
    }
};