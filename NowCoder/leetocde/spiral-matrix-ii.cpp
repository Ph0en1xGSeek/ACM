class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ans;
        if(n == 0) {
            return ans;
        }
        ans.resize(n, vector<int>(n));
        int cnt = 1;
        for(int start = 0; (start << 1) < n; ++start) {
            int length = n - (start << 1);
            for(int i = 0; i < length; ++i) {
                ans[start][start + i] = cnt++;
            }
            if(length > 1) {
                for(int i = 0; i < length - 1; ++i) {
                    ans[start + i + 1][start + length - 1] = cnt++;
                }
                for(int i = length - 2; i >= 0; --i) {
                    ans[start + length - 1][start + i] = cnt++;
                }
            }
            if(length > 2) {
                for(int i = length - 2; i > 0; --i) {
                    ans[start + i][start] = cnt++;
                }
            }
        }
        return ans;
    }
};