class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        long long tot = 1;
        int cnt_zero = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                tot *= nums[i];
            }else {
                ++cnt_zero;
            }
        }
        if(cnt_zero == 0) {
            for(int i = 0; i < nums.size(); ++i) {
                res.push_back(tot / nums[i]);
            }
        }else if(cnt_zero == 1) {
            for(int i = 0; i < nums.size(); ++i) {
                if(nums[i] != 0) {
                    res.push_back(0);
                }else {
                    res.push_back(tot);
                }
            }
        }else {
            for(int i = 0; i < nums.size(); ++i) {
                res.push_back(0);
            }
        }
        
        return res;
    }
};