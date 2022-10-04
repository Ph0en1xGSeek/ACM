class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 3) {
            return false;
        }
        int one = 0x7fffffff, two = 0x7fffffff, three = 0x7fffffff;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] <= one) {
                one = nums[i];
            }else if(nums[i] <= two) {
                two = nums[i];
            }else {
                return true;
            }
        }
        return false;
    }
};