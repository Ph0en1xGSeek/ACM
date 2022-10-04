class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if(len < 2){
            return 0;
        }
        int mi = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < len; i++){
            mi = min(mi, nums[i]);
            mx = max(mx, nums[i]);
        }
        if(mi == mx)
            return 0;
        double bracket_size = (mx - mi) * 1.0 / (len - 1.0);
        int bracket_num = floor((mx - mi) / bracket_size + 1);
        vector<int> bracket_mx(bracket_num, INT_MIN);
        vector<int> bracket_mi(bracket_num, INT_MAX);
        for(int i = 0; i < len; i++){
            int pos = floor((nums[i] - mi) / bracket_size);
            bracket_mx[pos] = max(bracket_mx[pos], nums[i]);
            bracket_mi[pos] = min(bracket_mi[pos], nums[i]);
        }
        int ans = INT_MIN;
        int pre_max = bracket_mx[0];
        for(int i = 1; i < bracket_num; i++){
            if(bracket_mi[i] != INT_MAX){
                ans = max(ans, bracket_mi[i] - pre_max);
                pre_max = bracket_mx[i];
            }
        }
        return ans;
    }
};