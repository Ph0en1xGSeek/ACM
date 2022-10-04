class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int cur = nums[0];
        int num = 1;
        for (int i = 1; i < size; ++i) {
            if (num == 0) {
                cur = nums[i];
                num = 1;
            } else if (nums[i] != cur) {
                --num;
            } else {
                ++num;
            }
        }
        int cnt = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] == cur) {
                ++cnt;
            }
        }
        if ((cnt << 1) > size) {
            return cur;
        } else {
            return -1;
        }
    }
};