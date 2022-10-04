class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for(auto item: nums) {
            xorSum ^= item;
        }
        int tmp = 1;
        while((tmp & xorSum) == 0) {
            tmp <<= 1;
        }
        int sum1 = 0, sum2 = 0;
        for(auto item: nums) {
            if((item & tmp) != 0) {
                sum1 ^= item;
            }else {
                sum2 ^= item;
            }
        }
        return vector<int>{sum1, sum2};
    }
};