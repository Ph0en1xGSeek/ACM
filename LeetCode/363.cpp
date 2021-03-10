class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int sz_r = matrix.size();
        if(sz_r == 0) {
            return 0;
        }
        int sz_c = matrix[0].size();
        if(sz_c == 0) {
            return 0;
        }
        int ret = INT_MIN;
        for(int i = 0; i < sz_c; ++i) {
            vector<int> sum_r(sz_r, 0);
            for(int j = i; j < sz_c; ++j) {
                for(int r = 0; r < sz_r; ++r) {
                    sum_r[r] += matrix[r][j];
                }
                int cur_sum = 0;
                set<int> st;
                st.insert(0);
                int cur_max = INT_MIN;
                for(int r = 0; r < sz_r; ++r) {
                    cur_sum += sum_r[r];
                    auto iter = st.lower_bound(cur_sum - k);
                    if(iter != st.end()) {
                        cur_max = max(cur_max, cur_sum - *iter);
                    }
                    st.insert(cur_sum);
                }
                ret = max(ret, cur_max);
            }
        }
        return ret;
    }
};