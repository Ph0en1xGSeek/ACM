class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size()) {
            while(j < nums.size() && nums[j] == 0) {
                ++j;
            }
            if(j < nums.size()) {
                nums[i] = nums[j];
                ++i;
                ++j;
            }
        }
        while(i < nums.size()) {
            nums[i] = 0;
            ++i;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[tmp++] = nums[i];
            }
        }
        for (; tmp < nums.size(); ++tmp) {
            nums[tmp] = 0;
        }
    }
};