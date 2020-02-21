class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        if(sz == 0) {
            return 0;
        }
        vector<int> nums(sz, 1);
        int tmp = 1;
        for(int i = 1; i < sz; ++i) {
            if(ratings[i] > ratings[i-1]) {
                nums[i] = ++tmp;
            }else {
                tmp = 1;
            }
        }
        int ans = nums[sz - 1];
        tmp = 1;
        for(int i = sz - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i+1]) {
                ans += max(++tmp, nums[i]);
            }else {
                tmp = 1;
                ans += nums[i];
            }
        }
        return ans;
    }
};