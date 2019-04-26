class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int tmp1, tmp2;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == tmp1) {
                ++cnt1;
            }else if(nums[i] == tmp2) {
                ++cnt2;
            }else if(cnt1 == 0) {
                tmp1 = nums[i];
                cnt1 = 1;
            }else if(cnt2 == 0) {
                tmp2 = nums[i];
                cnt2 = 1;
            }else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == tmp1) {
                ++cnt1;
            }else if(nums[i] == tmp2) {
                ++cnt2;
            }
        }
        vector<int> res;
        if(cnt1 > nums.size() / 3) {
            res.push_back(tmp1);
        }
        if(cnt2 > nums.size() / 3) {
            res.push_back(tmp2);
        }
        return res;
    }
};