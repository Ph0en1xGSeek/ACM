class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long m = 1;
        int i = 0;
        int cnt = 0;
        int sz = nums.size();
        while(m <= n) {
            if(i < sz && nums[i] <= m) {
                m += nums[i++];
            }else {
                m <<= 1;
                ++cnt;
            }
        }
        return cnt;
    }
};