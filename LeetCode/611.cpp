class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < size-2; ++i) {
            int left = i + 1;
            int right = i + 2;
            while(right < size) {
                while(right < size && nums[right] < nums[i] + nums[left]) {
                    ++right;
                }
                while(left < right && (right == size || nums[i] + nums[left] <= nums[right])) {
                    ans += right - left - 1;
                    ++left;
                }
                if(left == right) {
                    ++right;
                }
            }
            
        }
        return ans;
    }
};