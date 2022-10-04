class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mi = nums[0], mx = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int tmp1 = mi * nums[i];
            int tmp2 = mx * nums[i];
            
            mx = max(max(tmp1, tmp2), nums[i]);
            mi = min(min(tmp1, tmp2), nums[i]);
            result = max(result, mx);
        }
        return result;
    }
};