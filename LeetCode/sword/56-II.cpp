class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        int size = nums.size();
        for(int i = 0; i < size; ++i) {
            int tmp = one & nums[i];
            one ^= nums[i];
            one &= (~two);
            two ^= nums[i];
            two &= (~one);
        }
        return one;
    }
};