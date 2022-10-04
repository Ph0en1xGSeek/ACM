class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) {
            return vector<int>(1, 0);
        }
        vector<int> ans(num+1, -1);
        ans[0] = 0;
        ans[1] = 1;
        int tmp = 1;
        int i = 2;
        while(i <= num) {
            for(int j = 0; i <= num && j <= tmp; ++i, ++j) {
                ans[i] = ans[j] + 1;
            }
            tmp = i-1;
        }
        return ans;
    }
};