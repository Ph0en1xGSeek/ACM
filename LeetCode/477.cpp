class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        if(size < 2) {
            return ans;
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < 31; ++i) {
            cnt1 = cnt2 = 0;
            for(int j = 0; j < size; ++j) {
                if(nums[j] & (1 << i)) {
                    ++cnt1;
                }else {
                    ++cnt2;
                }
            }
            ans += cnt2 * cnt1;
        }
        return ans;
    }
};