class Solution {
public:
    vector<double> twoSum(int n) {
        int size = n * 6;
        vector<double> ans(size, 0);
        for(int i = 0; i < 6; ++i) {
            ans[i] = 1.0 / 6;
        }
        for(int i = 2; i <= n; ++i) {
            int j;
            for(j = i * 6 - 1; j >= i - 1; --j) {
                int k;
                ans[j] = 0;
                for(k = j - 1; k >= 0 && k >= j - 6; --k) {
                    ans[j] += ans[k] * (1.0 / 6);
                }
            }
            while(j >= 0) {
                ans[j] = 0;
                --j;
            }
        }
        copy(ans.begin() + n - 1, ans.end(), ans.begin());
        ans.resize(n * 5 + 1);
        return ans;
    }
};