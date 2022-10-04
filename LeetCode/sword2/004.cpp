class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < size; ++i) {
            two |= (one & nums[i]);
            one ^= nums[i];
            three = (one & two);
            two ^= three;
            one ^= three;
        }
        return one;
    }
};