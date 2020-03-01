class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < sz; i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};