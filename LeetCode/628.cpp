class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int size = nums.size();
        int mx = INT_MIN, second = INT_MIN, third = INT_MIN, mi = INT_MAX, mi_second = INT_MAX;
        for(int i = 0; i < size; ++i) {
            if(nums[i] > mx) {
                third = second;
                second = mx;
                mx = nums[i];
            }else if(nums[i] > second) {
                third = second;
                second = nums[i];
            }else if(nums[i] > third) {
                third = nums[i];
            }
            if(nums[i] < mi) {
                mi_second = mi;
                mi = nums[i];
            }else if(nums[i] < mi_second) {
                mi_second = nums[i];
            }
        }
        int ans = mi * mi_second * mx;
        ans = max(ans, mx * second * third);
        return ans;
    }
};