class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 2)
            return sz;
        int ans = 1;
        int pos = 1;
        while(pos < sz && nums[pos] == nums[pos-1]) ++pos;
        int flag;
        if(pos < sz) {
            flag = nums[pos] > nums[0]? 1: 0;
        }else {
            return ans;
        }
        while(pos < sz) {
            if(flag == 1) {
                while(pos+1 < sz && nums[pos+1] >= nums[pos]) ++pos;
            }else {
                while(pos+1 < sz && nums[pos+1] <= nums[pos]) ++pos;
            }
            ++ans;
            flag ^= 1;
            ++pos;
        }
        return ans;
    }
};