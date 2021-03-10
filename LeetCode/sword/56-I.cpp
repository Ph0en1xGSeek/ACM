class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int size = nums.size();
        int tot = 0;
        for(int i = 0; i < size; ++i) {
            tot ^= nums[i];
        }
        int pos = 0, tot1 = 0, tot2 = 0;
        for(pos = 0; pos < 32; ++pos) {
            if(((1 << pos) & tot) != 0) {
                break;
            }
        }
        for(int i = 0; i < size; ++i) {
            if((nums[i] & (1 << pos)) == 0) {
                tot1 ^= nums[i];
            }else {
                tot2 ^= nums[i];
            }
        }
        return {tot1, tot2};
    }
};