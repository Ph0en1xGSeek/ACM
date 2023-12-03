class Solution {
public:
    int crackNumber(int ciphertext) {
        vector<int> nums;
        while (ciphertext > 0) {
            nums.push_back(ciphertext % 10);
            ciphertext /= 10;
        }
        reverse(nums.begin(), nums.end());
        int cur = 1;
        int pre = 1;
        int pre_pre = 0;
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            pre_pre = pre;
            pre = cur;
            if (nums[i - 1] == 1 || (nums[i - 1] == 2 && nums[i] < 6)) {
                cur += pre_pre;
            }
        }
        return cur;
    }
};