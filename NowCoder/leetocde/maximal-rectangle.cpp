class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int rows = matrix.size();
        if(rows == 0) {
            return 0;
        }
        int cols = matrix[0].size();
        if(cols == 0) {
            return 0;
        }
        vector<int> height(cols, 0);
        vector<int> left(cols, 0);
        vector<int> right(cols, 0);
        stack<int> left_st, right_st;
        int ans = 0;
        for(int row = 0; row < rows; ++row) {
            while(!left_st.empty()) {
                left_st.pop();
            }
            while(!right_st.empty()) {
                right_st.pop();
            }
            for(int i = 0; i < cols; ++i) {
                if(matrix[row][i] == '1') {
                    ++height[i];
                }else {
                    height[i] = 0;
                }
                while(!left_st.empty() && height[left_st.top()] >= height[i]) {
                    left_st.pop();
                }
                if(left_st.empty()) {
                    left[i] = -1;
                }else {
                    left[i] = left_st.top();
                }
                left_st.push(i);
            }
            for(int i = cols-1; i >= 0; --i) {
                while(!right_st.empty() && height[right_st.top()] >= height[i]) {
                    right_st.pop();
                }
                if(right_st.empty()) {
                    right[i] = cols;
                }else {
                    right[i] = right_st.top();
                }
                right_st.push(i);
            }
            for(int i = 0; i < cols; ++i) {
                ans = max(ans, height[i] * (right[i] - left[i] - 1));
            }
        }
        return ans;
    }
};