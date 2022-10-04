class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 1) {
            return sz;
        }
        int r = sz - 1, l = 0;
        int mx = INT_MIN, mi = INT_MAX;
        int acend_l = -2, decend_r = -1;
        while(l < sz) {
            mi = min(mi, nums[r]);
            mx = max(mx, nums[l]);
            if(mi != nums[r]) {
                decend_r = r;
            }
            if(mx != nums[l]) {
                acend_l = l;
            }
            ++l;
            --r;
        }
        return acend_l - decend_r + 1;
    }
};