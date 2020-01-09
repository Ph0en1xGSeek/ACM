class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int l = 1, r = 2;
        vector<vector<int>> ans;
        while(r <= sum && l < r) {
            if((l + r) * (r - l + 1) < 2 * sum) {
                ++r;
            }else if((l + r) * (r - l + 1) > 2 * sum) {
                ++l;
            }else {
                ans.push_back(vector<int>(r - l + 1));
                for(int i = 0; i < r-l+1; ++i) {
                    ans.back()[i] = i + l;
                }
                ++l;
                ++r;
            }
        }
        return ans;
    }
};