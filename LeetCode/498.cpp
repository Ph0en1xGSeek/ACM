class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        pair<int, int> from = {0, 0}, to = {0, 0};
        int x, y;
        vector<int> ret;
        int pos = 0;
        int m = matrix.size();
        if(m == 0) {
            return ret;
        }
        int n = matrix[0].size();
        if(n == 0) {
            return ret;
        }
        ret.resize(m * n);
        for(int i = 0; i < m + n - 1; ++i) {
            if(i % 2 == 0) {
                x = from.first;
                y = from.second;
                while(x >= to.first) {
                    ret[pos++] = matrix[x][y];
                    --x;
                    ++y;
                }
            }else {
                x = to.first;
                y = to.second;
                while(x <= from.first) {
                    ret[pos++] = matrix[x][y];
                    ++x;
                    --y;
                }
            }
            
            if(from.first < m - 1) {
                ++from.first;
            }else {
                ++from.second;
            }
            
            if(to.second < n - 1) {
                ++to.second;
            }else {
                ++to.first;
            }
        }
        return ret;
    }
};